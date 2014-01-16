/*
 ============================================================================
 Name        : configuration.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Reads server command line options and config file(s)
 ============================================================================
 */
 
#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <vector>

#include <boost/filesystem/path.hpp>

// media server configuration
class Configuration {
private:
	// stores all config files
	std::vector<boost::filesystem::path> _configFiles;

	// host address for UPnP
	std::string _hostAddress;
	
	// port used for UPnP
	unsigned short _port;
	
	// root directories for the UPnP server
	std::vector<boost::filesystem::path> _rootDirectories;

public:
	// create default configuration
	Configuration();
	
	// destroy configuration
	virtual ~Configuration();
	
	// parse command line arguments
	void parse(int argc, char **argv);
	
	// parse found config files
	void parseConfigFiles();
	
	// parse config file
	bool parseConfigFile(boost::filesystem::path configFilePath);
	
private:
	
};

#endif /* CONFIGURATION_H */