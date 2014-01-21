/*
 ============================================================================
 Name        : header.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Represents a HTTP request header
 ============================================================================
 */
 
#ifndef HEADER_H
#define HEADER_H

#include <string>

namespace http {

struct header {
	std::string name;
	std::string value;
};

}

#endif /* HEADER_H */