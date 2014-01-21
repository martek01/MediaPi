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

Configuration::Configuration() : _globalOptions("Global options"), _commandLineOptions("Command line options"), _configGlobalOptions("Config global options") {

}

Configuration::~Configuration() {

}

void Configuration::parse(int argc, char **argv) {
	// get allowed options
	boost::program_options::options_description options;
	options.add(_globalOptions).add(_commandLineOptions);
	
	// parse command-line
	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, options), _variablesMap);
	boost::program_options::notify(_variablesMap);
}

void Configuration::parseConfigFiles() {

}

bool Configuration::parseConfigFile(boost::filesystem::path configFilePath) {

}

void Configuration::createOptionDescriptions() {
	// create global options
	_globalOptions.add_options()
	;
	
	// create command-line only options
	_commandLineOptions.add_options()
		("help,h", "Show this help message")
		("version,v", "Print version string")
	;
	
	// create config file(s) only global options
	_configGlobalOptions.add_options()
		("host", boost::program_options::value<std::string>(&config::hostAddress), "Host address for UPnP server")
		("port", boost::program_options::value<unsigned short>(&config::port), "Host port for UPnP server")
	;
}
