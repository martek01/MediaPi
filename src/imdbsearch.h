/*
 ============================================================================
 Name        : imdbsearch.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Search imdb.com for movies and series metadata
 ============================================================================
 */
 
#ifndef IMDB_SEARCH_H
#define IMDB_SEARCH_H

#include <string>
#include <vector>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

class IMDBSearch {
private:
	// socket for HTTP requests
	boost::asio::ip::tcp::socket _socket;

public:
	// create imdb.com search object
	IMDBSearch(boost::asio::io_service &ioService);
	
	// destroy imdb.com search object
	virtual ~IMDBSearch();
	
	// search for the default title for the given filename
	std::string searchDefaultTitle(std::string fileName);
	
	// search for all titles for the given filename
	bool searchTitles(std::string filename, std::vector<std::string> &titles);

private:
	// parse the response XML body for titles
	bool parseResponse(std::string response, std::vector<std::string> &titles);

};

#endif /* IMDB_SEARCH_H */
