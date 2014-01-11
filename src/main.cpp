/*
 ============================================================================
 Name        : main.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 
 Description : UPnP media server for Raspberry Pi
 ============================================================================
 */

#include <iostream>
#include <sqlite3.h>
#include <boost/filesystem/path.hpp>

int main(int argc, char **argv) {
	sqlite3 *database;

	// open database
	int rc = sqlite3_open("test.db", &database);
	if (rc) {
		std::cout << "Can't open database: " << sqlite3_errmsg(database) << std::endl;
		sqlite3_close(database);
		return 1;
	}

	// do something
	std::cout << "Database opened!" << std::endl;

	// close database
	sqlite3_close(database);

	// create boost filesystem path
	boost::filesystem::path filePath("./test.db");

	return 0;
}
