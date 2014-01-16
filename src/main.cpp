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

#include "upnp/rootdevice.h"

int main(int argc, char **argv) {
	/*
	// create default configuration
	Configuration config;
	
	// parse command line arguments
	config.parse(argc, argv);
	
	// parse config files
	config.parseConfigFiles();
	*/
	
	// test multicast sender
	boost::asio::io_service ioService;
	
	RootDevice rootDevice(ioService, "");
	rootDevice.setOSDescription("OS X/10.9.1");
	rootDevice.setProductDescription("MediaPi/0.1");
	
	rootDevice.sendDeviceAvailable();
	
	ioService.run();

	return 0;
}
