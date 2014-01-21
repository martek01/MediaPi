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

#include <vector>

#include <boost/asio/io_service.hpp>

#include "multicastsender.h"

class BasicDevice;

// UPnP root device
class RootDevice {
private:
	// UPnP uuid
	std::string _uuid;
	
	// operationsystem name and version for discovery separated with a slash
	std::string _osDescription;
	
	// product name and version for discovery separated with a slash
	std::string _productDescription;
	
	// 
	std::string _location;
	
	// multicast sender for sending ssdp messages
	MulticastSender _multicastSender;
	
	// list of UPnP devices belonging to this root device
	std::vector<BasicDevice *> _devices;

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
	
	// add an UPnP device to this root device
	void addDevice(BasicDevice *device);
	
	// remove an UPnP device from this root device
	void removeDevice(BasicDevice *device);
	
private:
	// send notify multicast message with given type and headers (basic + specified additional)
	void sendNotify(std::string ssdpType, std::string additionalHeader);
};

#endif /* ROOT_DEVICE_H */