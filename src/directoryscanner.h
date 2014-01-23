/*
 ============================================================================
 Name        : directoryscanner.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Scans media directories for AV media content
 ============================================================================
 */
 
#ifndef DIRECTORY_SCANNER_H
#define DIRECTORY_SCANNER_H

#include <vector>
#include <string>

#include <boost/filesystem/path.hpp>

class Database;

class DirectoryScanner {
private:
	//
	Database *_database;
	
	//
	std::vector<std::string> _allowedExtensions;

public:
	//
	DirectoryScanner(Database *database);
	
	//
	virtual ~DirectoryScanner();
	
	//
	void scanDirectory(boost::filesystem::path directory);
	
	//
	void setAllowedExtensions(std::vector<std::string> allowedExtensions);
	
	//
	std::vector<std::string> allowedExtensions() const;
	
private:
	//
	void addFileToDatabase(boost::filesystem::path filePath);
	
	//
	bool isAllowedExtension(boost::filesystem::path extension);
};

#endif /* DIRECTORY_SCANNER_H */
