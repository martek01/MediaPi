/*
 ============================================================================
 Name        : Connection.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Connections representing a http client-server connection
 ============================================================================
 */

#include "connection.h"

#include "requesthandler.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace http {

Connection::Connection(boost::asio::io_service &ioService, RequestHandler &requestHandler) : _socket(ioService), _requestHandler(requestHandler) {

}

Connection::~Connection() {
	// close connection
	stop();
}

boost::asio::ip::tcp::socket &Connection::socket() {
	return _socket;
}

void Connection::start() {
	// start reading some bytes
	_socket.async_read_some(boost::asio::buffer(_buffer), boost::bind(&Connection::handleRead, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Connection::stop() {
	// close connection
	_socket.close();
}

void Connection::handleRead(const boost::system::error_code &error, std::size_t bytesTransferred) {
	if (!error) {
		// parse buffer for request
		request request;
		boost::tribool result = _requestParser.parse(request, _buffer.data(), _buffer.data() + bytesTransferred);
		
		// handle request depending on the parse result
		if (result) {
			// request was ok
			response response = _requestHandler.handleRequest(request);
			boost::asio::async_write(_socket, , boost::bind(&Connection::handleWrite, this, boost::asio::placeholders::error));
		} else if (!result) {
			// request was not ok so answer with bad request response
			
		} else {
			// more data needs to be parses
			socket.async_read_some(boost::asio::buffer(_buffer), boost::bind(&Connection::handleRead, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		}
	} else if (error != boost::asio::error::operation_aborted) {
		
	}
}

void Connection::handleWrite(const boost::system::error_code &error) {
	if (!error) {
	
	}
}

}
