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

#include "mediaserver.h"

#include <platinum.h>

int main(int argc, char **argv) {
	/*
	// create default configuration
	Configuration config;
	
	// parse command line arguments
	config.parse(argc, argv);
	
	// parse config files
	config.parseConfigFiles();
	*/
	
	PLT_UPnP upnp;
	
	MediaServer server("/users/markusgrigull/movies/handbrake", "MediaPi");
	PLT_DeviceHostReference serverRef(&server);
	upnp.AddDevice(serverRef);
	
	upnp.Start();
	
	while (upnp.IsRunning());
	
	return 0;
}
