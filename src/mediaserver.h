/*
 ============================================================================
 Name        : mediaserver.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Abstracts platinum file media server
 ============================================================================
 */

#ifndef MEDIA_SERVER_H
#define MEDIA_SERVER_H

#include <pltfilemediaserver.h>

class MediaServer : public PLT_MediaServer, public PLT_FileMediaServerDelegate {
private:


public:
	//
	MediaServer(const char *fileRoot, const char *friendlyName, bool showIP = false, const char *uuid = NULL, NPT_UInt16 port = 0, bool portRebind = false);
	
	//
	virtual ~MediaServer();

private:


};

#endif /* MEDIA_SERVER_H */
