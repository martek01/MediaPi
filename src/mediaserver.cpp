/*
 ============================================================================
 Name        : mediaserver.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : 
 ============================================================================
 */

#include "mediaserver.h"

MediaServer::MediaServer(const char *fileRoot, const char *friendlyName, bool showIP, const char *uuid, NPT_UInt16 port, bool portRebind) : PLT_MediaServer(friendlyName, showIP, uuid, port, portRebind), PLT_FileMediaServerDelegate("/", fileRoot) {
	// set self as delegate
	SetDelegate(this);
}

MediaServer::~MediaServer() {

}
