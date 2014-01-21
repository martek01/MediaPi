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

namespace config {

// UPnP
extern std::string hostAddress;
extern unsigned short port;

// root device
extern std::string rootDeviceUuid;
extern std::string rootDeviceOsDescription;
extern std::string rootDeviceProductDescription;
extern std::string rootDeviceLocation;

}

#endif /* CONFIGS_H */
