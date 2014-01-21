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
#include <boost/program_options.hpp>

#include "configs.h"

// media server configuration
class Configuration {
private:
	// stores all config files
	std::vector<boost::filesystem::path> _configFiles;
	
	// root directories for the UPnP server
	std::vector<boost::filesystem::path> _rootDirectories;
	
	// stores all options for boost::program_options
	boost::program_options::variables_map _variablesMap;
	
	// global options
	boost::program_options::options_description _globalOptions;
	
	// command-line only options
	boost::program_options::options_description _commandLineOptions;
	
	// config file(s) only global options
	boost::program_options::options_description _configGlobalOptions;

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
	// create option descriptions needed by the parsing
	void createOptionDescriptions();
	
};

#endif /* CONFIGURATION_H */