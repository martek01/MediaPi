/*
 ============================================================================
 Name        : configuration.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Reads server command line options and config file(s)
 ============================================================================
 */

#include "configuration.h"

#include <iostream>
#include <fstream>

#include <boost/bind.hpp>

Configuration::Configuration() : _globalOptions("Global options"), _commandLineOptions("Command line options"), _configGlobalOptions("Config global options") {
	// create option descriptions
	createOptionDescriptions();
}

Configuration::~Configuration() {

}

void Configuration::parse(int argc, char **argv) {
	// get allowed options
	boost::program_options::options_description options;
	options.add(_globalOptions).add(_commandLineOptions);
	
	// parse command-line
	try {
		boost::program_options::store(boost::program_options::parse_command_line(argc, argv, options), _variablesMap);
		boost::program_options::notify(_variablesMap);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Configuration::parseConfigFiles() {

}

void Configuration::parseConfigFile(boost::filesystem::path configFilePath) {
	// get allowed options
	boost::program_options::options_description options;
	options.add(_globalOptions).add(_configGlobalOptions);
	
	// parse config file
	try {
		// open file
		std::ifstream configFile(configFilePath.string());
		
		// parse
		boost::program_options::store(boost::program_options::parse_config_file(configFile, options), _variablesMap);
		boost::program_options::notify(_variablesMap);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "Media: ";
	
	for (std::vector<boost::filesystem::path>::iterator it = config::mediaDirectories.begin(); it != config::mediaDirectories.end(); it++) {
		std::cout << *it << ", ";
	}
	
	std::cout << std::endl;
}

void Configuration::createOptionDescriptions() {
	// create global options
	_globalOptions.add_options()
	;
	
	// create command-line only options
	_commandLineOptions.add_options()
		("help,h", "Show this help message.")
		("version,v", "Print version string.")
		("config,c", boost::program_options::value<boost::filesystem::path>()->notifier(boost::bind(&Configuration::parseConfigFile, this, _1)), "Load configuration file(s)")
	;
	
	// create config file(s) only global options
	_configGlobalOptions.add_options()
		("host", boost::program_options::value<std::string>(&config::hostAddress), "Host address for UPnP server.")
		("port", boost::program_options::value<unsigned short>(&config::port), "Host port for UPnP server.")
		("uuid", boost::program_options::value<std::string>(&config::uuid), "UPnP root device UUID. Set Null for random UUID.")
		//("media", boost::program_options::value<std::vector<boost::filesystem::path> >(&config::mediaDirectories)->composing(), "Directories containing AV media.")
	;
}
