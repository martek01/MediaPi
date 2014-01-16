/*
 ============================================================================
 Name        : multicastsender.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Sends UDP multicast messages for UPnP
 ============================================================================
 */
 
#ifndef MULTICAST_SENDER_H
#define MULTICAST_SENDER_H

#include <string>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/udp.hpp>

// UDP multicast sender
class MulticastSender {
private:
	// socket for UDP connection
	boost::asio::ip::udp::socket *_socket;
	
	// endpoint for multicast messages
	boost::asio::ip::udp::endpoint _endpoint;

public:
	// create multicast sender for default ssdp address and port
	MulticastSender(boost::asio::io_service &ioService);
	
	// create multicast sender for specific address and port
	MulticastSender(boost::asio::io_service &ioService, const boost::asio::ip::address &multicastAddress, const unsigned short port = 1900);
	
	// destroy multicast sender
	virtual ~MulticastSender();
	
	// send multicast message
	void sendMessage(const std::string &message);
	
private:
	// handles sent multicast message
	void handleSendTo(const boost::system::error_code &error);
};

#endif /* MULTICAST_SENDER_H */