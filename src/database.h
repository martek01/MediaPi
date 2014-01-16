/*
 ============================================================================
 Name        : database.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Handles media database
 ============================================================================
 */
 
#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include <boost/filesystem/path.hpp>

#include <sqlite3.h>

// media database
class Database {
private:
	// stores database file path
	boost::filesystem::path _databaseFile;

public:
	// create default configuration
	Database(boost::filesystem::path databaseFile);
	
	// destroy configuration
	virtual ~Database();
	
	// open database
	bool open();
	
	// check whether the database is open
	bool isOpen();
	
	// close the database
	void close();
	
private:
	
};

#endif /* DATABASE_H */