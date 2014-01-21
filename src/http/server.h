/*
 ============================================================================
 Name        : server.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Basic HTTP server
 ============================================================================
 */
 
#ifndef SERVER_H
#define SERVER_H

#include <vector>

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/noncopyable.hpp>

namespace http {

class Connection;
class RequestHandler;

// Basic HTTP server
class Server {
private:
	// boost asio io service
	boost::asio::io_service _ioService;
	
	// is responsible for accepting client connections
	boost::asio::ip::tcp::acceptor _acceptor;
	
	// the next client connection
	Connection *_nextConnection;
	
	// stores all open connections with clients
	std::vector<Connection *> _connections;
	
	//
	RequestHandler &_requestHandler;

public:
	// creates a new http server on the given port
	Server(unsigned short port, RequestHandler &requestHandler);
	
	// destroys the server
	virtual ~Server();
	
	// starts the service loop
	void run();
	
	// 
	void closeConnection(Connection *connection);

private:
	// starts accepting a new client connection
	void startAccept();
	
	// handles incoming data
	void handleAccept(const boost::system::error_code &error);
	
	// 
	void handleStop();
};

}

#endif /* SERVER_H */