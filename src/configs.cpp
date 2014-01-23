/*
 ============================================================================
 Name        : configs.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Stores all global configuration variables
 ============================================================================
 */

#include "configs.h"

namespace config {

// UPnP
std::string hostAddress;
unsigned short port;
std::string uuid;

// media
std::vector<boost::filesystem::path> mediaDirectories;
bool recursive;
boost::filesystem::path databaseFile;
bool uniqueFiles;

// metadata search
std::string imdbURL;

}
