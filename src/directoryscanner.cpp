/*
 ============================================================================
 Name        : directoryscanner.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Scans media directories for AV media content
 ============================================================================
 */

#include "directoryscanner.h"

#include "configs.h"
#include "database.h"

#include <iostream>

#include <boost/filesystem.hpp>

DirectoryScanner::DirectoryScanner(Database *database) : _database(database) {
	// set default extensions
	_allowedExtensions.push_back("m4v");
	
	_allowedExtensions.push_back("m4a");
	_allowedExtensions.push_back("mp3");
}

DirectoryScanner::~DirectoryScanner() {

}

void DirectoryScanner::scanDirectory(boost::filesystem::path directory) {
	// stop if path is not an existing directory
	if (!boost::filesystem::exists(directory) || !boost::filesystem::is_directory(directory)) {
		std::cout << "Path is not a valid directory: " << directory << std::endl;
		return;
	}
	
	// start scanning
	if (config::recursive) {
		// scan directory and all sub-directories
		for (boost::filesystem::recursive_directory_iterator endIt, it(directory); it != endIt; it++) {
			// check for allowed extensions
			if (isAllowedExtension(it->path().extension())) {
				addFileToDatabase(*it);
			}
		}
	} else {
		// scan directory only
		for (boost::filesystem::directory_iterator endIt, it(directory); it != endIt; it++) {
			// check for allowed extensions
			if (isAllowedExtension(it->path().extension())) {
				addFileToDatabase(*it);
			}
		}
	}
}

void DirectoryScanner::setAllowedExtensions(std::vector<std::string> allowedExtensions) {
	_allowedExtensions = allowedExtensions;
}

std::vector<std::string> DirectoryScanner::allowedExtensions() const {
	return _allowedExtensions;
}

void DirectoryScanner::addFileToDatabase(boost::filesystem::path filePath) {
	// add file to database
	_database->addFile(filePath);
}

bool DirectoryScanner::isAllowedExtension(boost::filesystem::path extension) {
	// get extension
	std::string extString = extension.string();
	extString.erase(0, 1);	// boost::filesystem gives extension with as '.xxx'
	
	// search for extension
	for (std::vector<std::string>::iterator it = _allowedExtensions.begin(); it != _allowedExtensions.end(); it++) {
		if (extString.compare(*it) == 0) {
			return true;
		}
	}
	
	return false;
}
