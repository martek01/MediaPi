/*
 ============================================================================
 Name        : imdbsearch.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Search imdb.com for movies and series metadata
 ============================================================================
 */

#include "imdbsearch.h"

#include "configs.h"

#include <iostream>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

IMDBSearch::IMDBSearch(boost::asio::io_service &ioService) : _socket(ioService) {
	// get endpoint for socket
	try {
		boost::asio::ip::tcp::resolver resolver(ioService);
		boost::asio::ip::tcp::resolver::query resolverQuery(config::imdbURL, "http");
		boost::asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve(resolverQuery);
		
		// connect socket
		boost::asio::connect(_socket, endpointIterator);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

IMDBSearch::~IMDBSearch() {

}

std::string IMDBSearch::searchDefaultTitle(std::string fileName) {
	// get first title which is the default one from imdb.com
	std::vector<std::string> titles;
	searchTitles(fileName, titles);
	
	if (titles.size() > 0) {
		return titles.at(0);
	} else {
		return "";
	}
}

bool IMDBSearch::searchTitles(std::string fileName, std::vector<std::string> &titles) {
	// create request
	boost::asio::streambuf request;
	std::ostream requestStream(&request);
	
	// request header
	requestStream << "GET /xml/find?json=1&nr=1&tt=on&q=" + fileName + " HTTP/1.0\r\n";
	requestStream << "Host: " << config::imdbURL << "\r\n";
	requestStream << "Accept: */*\r\n";
	requestStream << "Accept-Language: en-us\r\n";
	requestStream << "\r\n";
	
	// send the request
	boost::asio::write(_socket, request);
	
	// read the response
	boost::asio::streambuf response;
	boost::asio::read_until(_socket, response, "\r\n");
	
	// check whether the reponse is OK
	std::istream responseStream(&response);
	
	std::string httpVersion;
	unsigned int statusCode;
	std::string statusMessage;
	
	responseStream >> httpVersion;
	responseStream >> statusCode;
	std::getline(responseStream, statusMessage);
	
	if (!responseStream || httpVersion.substr(0, 5).compare("HTTP/") != 0) {
		std::cout << "Invalid response" << std::endl;
		return false;
	}
	
	if (statusCode != 200) {
		std::cout << "Response returned with status code " << statusCode << std::endl;
		return false;
	}
	
	// read response 
	boost::system::error_code error;
	std::stringstream bodyStream;
	
	while (boost::asio::read(_socket, response, boost::asio::transfer_at_least(1), error)) {
		// write response part into body stream
		bodyStream << &response;
	}
	
	// catch reading error
	if (error != boost::asio::error::eof) {
		std::cout << "Error reading response body" << std::endl;
		return false;
	}
	
	return parseResponse(bodyStream.str(), titles);
}

bool IMDBSearch::parseResponse(std::string response, std::vector<std::string> &titles) {
	// get body
	std::size_t pos = response.find("\r\n\r\n");
	std::string body;
	
	if (pos != std::string::npos) {
		body = response.substr(pos + 4, response.length() - pos - 4);
	} else {
		body = response;
	}
	
	// parse JSON
	std::stringstream bodyStream;
	bodyStream << body;
	
	boost::property_tree::ptree propertyTree;
	boost::property_tree::read_json(bodyStream, propertyTree);
	
	// read titles
	BOOST_FOREACH(boost::property_tree::ptree::value_type &section, propertyTree) {
		BOOST_FOREACH(boost::property_tree::ptree::value_type &media, propertyTree.get_child(section.first)) {
			titles.push_back(media.second.get<std::string>("title"));
		}
	}
	
	return true;
}
