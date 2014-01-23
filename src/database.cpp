
/*
 ============================================================================
 Name        : database.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Handles media database
 ============================================================================
 */

#include "database.h"

#include <iostream>

Database::Database(boost::filesystem::path databaseFile) : _databaseFile(databaseFile) {
	
}

Database::~Database() {
	// close database if not already closed
	close();
}

bool Database::open() {
	// open database file
	int result = sqlite3_open(_databaseFile.string().c_str(), &_database);
	if (result) {
		std::cout << "Database could not be opened " << _databaseFile << ":" << sqlite3_errmsg(_database) << std::endl;
		sqlite3_close(_database);
		return false;
	}
	
	// check whether database structure needs to be build
	if (!isDatabaseStructureCreated()) {
		std::cout << "Creating database structure" << std::endl;
	
		createDatabaseStructure();
	}
	
	return true;
}

void Database::close() {
	sqlite3_close(_database);
}

void Database::addFile(boost::filesystem::path filePath) {
	// create row in files table
	std::string query = "INSERT INTO files (path, searchname, displayname) VALUES ('" + filePath.string() + "', '" + filePath.stem().string() + "', '" + filePath.stem().string() + "')";
	int result = sqlite3_exec(_database, query.c_str(), NULL, 0, 0);
	if (result) {
		std::cout << "File could not be add to database " << filePath << ": " << sqlite3_errmsg(_database) << std::endl;
	}
}

void Database::removeFile(boost::filesystem::path filePath) {
	// create row in files table
	std::string query = "DELETE FROM files WHERE path = '" + filePath.string() + "'";
	int result = sqlite3_exec(_database, query.c_str(), NULL, 0, 0);
	if (result) {
		std::cout << "File could not be removed from database " << filePath << ": " << sqlite3_errmsg(_database) << std::endl;
	}
}

void Database::listFiles() {
	// create row in files table
	std::string query = "SELECT path FROM files";
	sqlite3_stmt *statement;
	
	int result = sqlite3_prepare(_database, query.c_str(), -1, &statement, 0);
	if (result) {
		std::cout << "Error preparing query: " << sqlite3_errmsg(_database) << std::endl;
		return;
	}
	
	// read data
	while (1) {
		result = sqlite3_step(statement);
		if (result == SQLITE_ROW) {
			// read all columns of the row
			for (int i=0; i<sqlite3_column_count(statement); i++) {
				// print column text
				std::cout << sqlite3_column_text(statement, i) << std::endl;
			}
		} else if (result == SQLITE_DONE) {
			// done reading
			break;
		} else if (result == SQLITE_ERROR) {
			std::cout << "Error reading statement: " << sqlite3_errmsg(_database) << std::endl;
			return;
		}
	}
}

void Database::createDatabaseStructure() {
	// create media files table
	std::string query = "CREATE TABLE files (id INTEGER PRIMARY KEY AUTOINCREMENT, path, searchname, displayname, type, year INTEGER)";
	int result = sqlite3_exec(_database, query.c_str(), NULL, 0, 0);
	if (result) {
		std::cout << "Database table could not be created: " << sqlite3_errmsg(_database) << std::endl;
	}
}

bool Database::isDatabaseStructureCreated() {
	// check media files table
	std::string query = "SELECT id FROM files";
	int result = sqlite3_exec(_database, query.c_str(), NULL, 0, 0);
	if (result) {
		return false;
	}
	
	return true;
}
