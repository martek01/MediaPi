/*
 ============================================================================
 Name        : controlpoint.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : 
 ============================================================================
 */
 
#ifndef CONTROL_POINT_H
#define CONTROL_POINT_H

#include <string>

#include "multicastsender.h"

// UPnP control point
class ControlPoint {
private:
	// response delay for search responses (minimum 1 and max should be 5)
	int _responseDelay;
	
	// number of messages sent for each search requests
	int _messageCount;

	// multicast sender for discovering devices and services
	MulticastSender _multicastSender;

public:
	// 
	ControlPoint(boost::asio::io_service &ioService);
	
	// destroy control point
	virtual ~ControlPoint();
	
	// search for all UPnP devices and services
	void searchAll();
	
	// search for all UPnP root devices
	void searchRootDevices();
	
	// search for a particular device by it's uuid
	void searchDevice(std::string uuid);
	
	// search for all devices with specific type and version
	void searchDevices(std::string type, int version);
	
	// search for all services with specific type and version
	void searchServices(std::string type, int version);
	
	// set new response delay for searching
	void setResponseDelay(int delay);
	
	// get response delay
	int responseDelay() const;
	
	// set new message count for seach search requests
	void setMessageCount(int count);
	
	// get message count for search requests
	int messageCount() const;
		
private:
	// send multicast search request with specified target
	void search(std::string target);
};

#endif /* CONTROL_POINT_H */