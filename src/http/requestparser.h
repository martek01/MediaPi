/*
 ============================================================================
 Name        : requestparser.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Parses incoming requests
 ============================================================================
 */
 
#ifndef REQUEST_PARSER_H
#define REQUEST_PARSER_H

#include <boost/logic/tribool.hpp>

namespace http {

struct request;

// 
class RequestParser {
private:
	

public:
	// 
	RequestParser();
	
	// destroys the request handler
	virtual ~RequestParser();
	
	//
	template <typename InputIterator> boost::tribool parse(request &request, InputIterator begin, InputIterator end, InputIterator &length);

private:


};

}

#endif /* REQUEST_PARSER_H */