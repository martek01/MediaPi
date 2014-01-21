/*
 ============================================================================
 Name        : requestparser.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Parses incoming requests
 ============================================================================
 */

#include "requestparser.h"

#include "request.h"

namespace http {

RequestParser::RequestParser() {

}

RequestParser::~RequestParser() {

}

template <typename InputIterator> boost::tribool RequestParser::parse(request &request, InputIterator begin, InputIterator end, InputIterator &length) {
	// parse buffer
	InputIterator pos = begin;
	
	while (pos != end) {
		
	}
}

}
