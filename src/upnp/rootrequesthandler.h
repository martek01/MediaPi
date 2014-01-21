/*
 ============================================================================
 Name        : rootrequesthandler.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : 
 ============================================================================
 */
 
#ifndef ROOT_REQUEST_HANDLER_H
#define ROOT_REQUEST_HANDLER_H

#include "../http/requesthandler.h"

// 
class RootRequestHandler : public http::RequestHandler {
private:
	

public:
	// 
	RootRequestHandler();
	
	// destroys the root request handler
	virtual ~RootRequestHandler();
	
	//
	http::response &handleRequest(const http::request &request);

private:


};

#endif /* ROOT_REQUEST_HANDLER_H */