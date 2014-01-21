/*
 ============================================================================
 Name        : server.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Basic HTTP server
 ============================================================================
 */

#include "server.h"

#include "connection.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace http {

Server::Server(unsigned short port, RequestHandler &requestHandler) : _acceptor(_ioService), _requestHandler(requestHandler) {
	// create endpoint
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);

	// setup acceptor and start listening
	_acceptor.open(endpoint.protocol());
	_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
	_acceptor.bind(endpoint);
	_acceptor.listen();
	
	// start accepting clients
	startAccept();
}

Server::~Server() {

}

void Server::run() {
	// start io routine
	_ioService.run();
}

void Server::closeConnection(Connection *connection) {
	// remove from connections
	for (std::vector<Connection *>::iterator it = _connections.begin(); it != _connections.end(); it++) {
		if (*it == connection) {
			_connections.erase(it);
		}
	}
	
	// close connection
	connection->stop();
}

void Server::startAccept() {
	// create new connection for the acceptor
	_nextConnection = new Connection(_ioService, _requestHandler);
	
	// start accepting
	_acceptor.async_accept(_nextConnection->socket(), boost::bind(&Server::handleAccept, this, boost::asio::placeholders::error));
}

void Server::handleAccept(const boost::system::error_code &error) {
	// do not create a new connection if the acceptor is not open
	if (!_acceptor.is_open()) {
		return;
	}
	
	if (!error) {
		// save connection
		_connections.push_back(_nextConnection);
		
		// start connection
		_nextConnection->start();
	}
	
	// start accepting the next connection
	startAccept();
}

void Server::handleStop() {
	// stop accepting new connections
	_acceptor.close();
	
	// close all connections
	for (std::vector<Connection *>::iterator it = _connections.begin(); it != _connections.end(); it++) {
		// close connection
		(*it)->stop();
	}
}

}
