/*
 ============================================================================
 Name        : requesthandler.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Handles incoming requests and creates responses
 ============================================================================
 */
 
#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include "request.h"
#include "response.h"
#include "requestparser.h"

namespace http {

// 
class RequestHandler {
protected:
	

public:
	// 
	RequestHandler();
	
	// destroys the request handler
	virtual ~RequestHandler();
	
	//
	virtual response &handleRequest(const request &request) = 0;

private:


};

}

#endif /* REQUEST_HANDLER_H */