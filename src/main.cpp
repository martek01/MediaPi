/*
 ============================================================================
 Name        : main.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : UPnP media server (for Raspberry Pi)
 ============================================================================
 */

#include "configuration.h"

int main(int argc, char **argv) {
	// create default configuration
	Configuration config;
	
	// parse command line arguments
	config.parse(argc, argv);
	
	// parse config files
	config.parseConfigFiles();
	
	return 0;
}
