/*
 ============================================================================
 Name        : configs.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Stores all global configuration variables
 ============================================================================
 */
 
#ifndef CONFIGS_H
#define CONFIGS_H

#include <string>
#include <vector>

#include <boost/filesystem/path.hpp>

namespace config {

// UPnP
extern std::string hostAddress;
extern unsigned short port;
extern std::string uuid;

// media
extern std::vector<boost::filesystem::path> mediaDirectories;
extern bool recursive;
extern boost::filesystem::path databaseFile;
extern bool uniqueFiles;

}

#endif /* CONFIGS_H */
