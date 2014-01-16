/*
 ============================================================================
 Name        : rootdevice.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Represents UPnP root device 
 ============================================================================
 */
 
#ifndef ROOT_DEVICE_H
#define ROOT_DEVICE_H

#include "multicastsender.h"

// UPnP root device
class RootDevice {
private:
	// UPnP uuid
	std::string _uuid;
	
	// operationsystem name and version for discovery separated with a slash
	std::string _osDescription;
	
	// product name and version for discovery separated with a slash
	std::string _productDescription;
	
	std::string _location;
	
	// multicast sender for sending ssdp messages
	MulticastSender _multicastSender;

public:
	// create UPnP root device with specific uuid
	RootDevice(boost::asio::io_service &ioService, std::string uuid);
	
	// destroy root device
	virtual ~RootDevice();
	
	// send multicast device available message with seconds until advertisement expires
	void sendDeviceAvailable(int maxAge = 1800);
	
	// send multicast device no longer available message
	void sendDeviceUnavailable();
	
	// send multicast device update message
	void sendDeviceUpdate();
	
	// set new operationsystem description
	void setOSDescription(std::string description);
	
	// get operationsystem description
	std::string osDescription() const;
	
	// set new product description 
	void setProductDescription(std::string description);
	
	// get product description
	std::string productDescription() const;
	
private:
	// creates basic message header for ssdp notify messages
	void basicNotifyMessageWithSSDPType(std::stringstream &msgStream, int maxAge, std::string ssdpType) const;
};

#endif /* ROOT_DEVICE_H */