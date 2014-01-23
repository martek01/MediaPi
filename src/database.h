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
	
	// sqlite3 database handle
	sqlite3 *_database;

public:
	// create default configuration
	Database(boost::filesystem::path databaseFile);
	
	// destroy configuration
	virtual ~Database();
	
	// open database
	bool open();
	
	// close the database
	void close();
	
	// add a filepath to the database
	void addFile(boost::filesystem::path filePath);
	
	// remove file by path from database
	void removeFile(boost::filesystem::path filePath);
	
	// list all known files
	void listFiles();
	
private:
	// create new database structure
	void createDatabaseStructure();
	
	// checks whether the database structure needs to be created
	bool isDatabaseStructureCreated();
};

#endif /* DATABASE_H */