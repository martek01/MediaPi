/*
 ============================================================================
 Name        : connection.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Connections representing a http client-server connection
 ============================================================================
 */
 
#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio/ip/tcp.hpp>
#include <boost/array.hpp>

namespace http {

class RequestHandler;

// Represents a http client connection
class Connection {
private:
	// client socket 
	boost::asio::ip::tcp::socket _socket;
	
	// buffer for incoming data
	boost::array <char, 8192> _buffer;
	
	//
	RequestHandler &_requestHandler;

public:
	// creates a new connection including the socket for the connection
	Connection(boost::asio::io_service &ioService, RequestHandler &requestHandler);
	
	// destroys the connection
	virtual ~Connection();
	
	// get the socket for the connection
	boost::asio::ip::tcp::socket &socket();
	
	// start reading connection input
	void start();
	
	// close the connection
	void stop();

private:
	// handle incoming data
	void handleRead(const boost::system::error_code &error, std::size_t bytesTransferred);
	
	// 
	void handleWrite(const boost::system::error_code &error);

};

}

#endif /* HTTP_CONNECTION_H */