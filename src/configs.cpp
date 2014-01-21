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

// root device
std::string rootDeviceUuid;
std::string rootDeviceOsDescription;
std::string rootDeviceProductDescription;
std::string rootDeviceLocation;

}
