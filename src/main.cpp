/*
 ============================================================================
 Name        : main.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : UPnP media server (for Raspberry Pi)
 ============================================================================
 */

//#include "configuration.h"

#include "upnp/upnp.h"
#include "http/http.h"

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
	/*
	boost::asio::io_service ioService;
	
	RootDevice rootDevice(ioService, "0123456789");
	rootDevice.setOSDescription("OS X/10.9.1");
	rootDevice.setProductDescription("MediaPi/0.1");
	
	BasicDevice device1("schemas-upnp.org", "device", "MediaServer");
	rootDevice.addDevice(&device1);
	
	rootDevice.sendDeviceAvailable();
	*/
	/*
	ControlPoint cp(ioService);
	cp.searchDevices("MediaServer", 1);
	
	ioService.run();
	*/
	
	RootRequestHandler requestHandler;
	
	http::Server server(80, requestHandler);
	server.run();
	
	return 0;
}
