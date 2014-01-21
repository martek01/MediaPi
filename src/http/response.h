/*
 ============================================================================
 Name        : response.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Represents a HTTP response
 ============================================================================
 */
 
#ifndef RESPONSE_H
#define RESPONSE_H

#include "header.h"

#include <vector>

namespace http {

struct response {
	// HTTP status type
	enum statusType {
		OK = 200,
		CREATED = 201,
		ACCEPTED = 202,
		NO_CONTENT = 204,
		MULTIPLE_CHOICES = 300,
		MOVED_PERMANENTLY = 301,
		MOVED_TEMPORARILY = 302,
		NOT_MOTIFIED = 304,
		BAD_REQUEST = 400,
		UNAUTHORIZED = 401,
		FORBIDDEN = 403,
		NOT_FOUND = 404,
		INTERNAL_SERVER_ERROR = 500,
		NOT_IMPLEMENTED = 501,
		BAD_GATEWAY = 502,
		SERVICE_UNAVAILABLE = 503
	} status;
	
	// HTTP headers
	std::vector <header> headers;
	
	// response body
	std::string body;
};

}

#endif /* RESPONSE_H */