/*
 ============================================================================
 Name        : controlpoint.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : 
 ============================================================================
 */

#include "controlpoint.h"

#include <sstream>

ControlPoint::ControlPoint(boost::asio::io_service &ioService) : _responseDelay(1), _messageCount(3), _multicastSender(ioService) {

}

ControlPoint::~ControlPoint() {

}

void ControlPoint::searchAll() {
	search("ssdp:all");
}

void ControlPoint::searchRootDevices() {
	search("upnp:rootdevice");
}

void ControlPoint::searchDevice(std::string uuid) {
	// create target string
	std::stringstream stream;
	stream << "uuid" << uuid;

	search(stream.str());
}

void ControlPoint::searchDevices(std::string type, int version) {
	// create target string
	std::stringstream stream;
	stream << "urn:schemas-upnp-org:device:" << type << ":" << version;

	search(stream.str());
}

void ControlPoint::searchServices(std::string type, int version) {
	// create target string
	std::stringstream stream;
	stream << "urn:schemas-upnp-org:service:" << type << ":" << version;

	search(stream.str());
}

void ControlPoint::setResponseDelay(int delay) {
	_responseDelay = delay;
}

int ControlPoint::responseDelay() const {
	return _responseDelay;
}

void ControlPoint::setMessageCount(int count) {
	_messageCount = count;
}

int ControlPoint::messageCount() const {
	return _messageCount;
}

void ControlPoint::search(std::string target) {
	// create message header
	std::stringstream msgStream;
	
	msgStream << "M-SEARCH * HTTP/1.1\r\n";
	msgStream << "HOST: 239.255.255.250:1900\r\n";
	msgStream << "MAN: \"ssdp:discovery\"\r\n";
	msgStream << "MX: " << _responseDelay << "\r\n";
	msgStream << "ST: " << target << "\r\n";
	//msgStream << "USER-AGENT: \r\n";
	msgStream << "\r\n";
	
	// send search multiple times
	for (int i = 0; i < _messageCount; i++) {
		_multicastSender.sendMessage(msgStream.str());
	}
}
