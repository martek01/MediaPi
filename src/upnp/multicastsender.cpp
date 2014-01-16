/*
 ============================================================================
 Name        : multicastsender.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Sends UDP multicast messages for UPnP
 ============================================================================
 */

#include "multicastsender.h"

#include <iostream>

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

MulticastSender::MulticastSender(boost::asio::io_service &ioService) : _endpoint(boost::asio::ip::address::from_string("239.255.255.250"), 1900) {
	// create udp socket
	_socket = new boost::asio::ip::udp::socket(ioService, _endpoint.protocol());
}

MulticastSender::MulticastSender(boost::asio::io_service &ioService, const boost::asio::ip::address &multicastAddress, const unsigned short port) : _endpoint(multicastAddress, port) {
	// create udp socket
	_socket = new boost::asio::ip::udp::socket(ioService, _endpoint.protocol());
}

MulticastSender::~MulticastSender() {
	delete _socket;
}

void MulticastSender::sendMessage(const std::string &message) {
	// send multicast message
	_socket->async_send_to(boost::asio::buffer(message), _endpoint, boost::bind(&MulticastSender::handleSendTo, this, boost::asio::placeholders::error));
}

void MulticastSender::handleSendTo(const boost::system::error_code &error) {
	// if an error occured
	if (error) {
		std::cout << "Error sending message: " << error << std::endl;
	}
}
