/*
 ============================================================================
 Name        : request.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Represents a HTTP request
 ============================================================================
 */
 
#ifndef REQUEST_H
#define REQUEST_H

#include "header.h"

#include <vector>

namespace http {

struct request {
	//
	std::string method;
	
	//
	std::string uri;
	
	//
	int majorVersion;
	
	//
	int minorVersion;
	
	//
	std::vector <header> headers;
};

}

#endif /* REQUEST_H */