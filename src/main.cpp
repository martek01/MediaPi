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

#include "database.h"
#include "directoryscanner.h"

int main(int argc, char **argv) {
/*
	// create default configuration
	Configuration config;
	
	// parse command line arguments
	config.parse(argc, argv);
	
	// parse config files
	config.parseConfigFiles();
	*/
	
	// set configurations
	config::recursive = true;
	config::databaseFile = "mediapi.db";
	
	// open database
	Database db(config::databaseFile);
	db.open();
	
	// scan directory
	DirectoryScanner scanner(&db);
	scanner.scanDirectory("/Users/markusgrigull/movies/handbrake");
	
	db.listFiles();
	
	db.close();
	
	return 0;
}
