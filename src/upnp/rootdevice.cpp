/*
 ============================================================================
 Name        : rootdevice.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Represents UPnP root device 
 ============================================================================
 */

#include "rootdevice.h"

#include <sstream>

RootDevice::RootDevice(boost::asio::io_service &ioService, std::string uuid) : _multicastSender(ioService), _uuid(uuid) {
	
}

RootDevice::~RootDevice() {
	
}

void RootDevice::sendDeviceAvailable(int maxAge) {
	// send multicast discovery message
	std::stringstream msgStream;
	
	basicNotifyMessageWithSSDPType(msgStream, maxAge, "alive");
	
	msgStream << "NT: upnp:rootdevice\r\n";
	msgStream << "USN: uuid:" << _uuid << "::upnp:rootdevice\r\n";
	//msgStream << "BOOTID.UPNP.ORG: 0\r\n";
	//msgStream << "CONFIGID.UPNP.ORG: \r\n";
	//msgStream << "SEARCHPORT.UPNP.ORG: \r\n\r\n";
	
	_multicastSender.sendMessage(msgStream.str());
}

void RootDevice::sendDeviceUnavailable() {

}

void RootDevice::sendDeviceUpdate() {

}

void RootDevice::setOSDescription(std::string description) {
	_osDescription = description;
}

std::string RootDevice::osDescription() const {
	return _osDescription;
}

void RootDevice::setProductDescription(std::string description) {
	_productDescription = description;
}

std::string RootDevice::productDescription() const {
	return _productDescription;
}

void RootDevice::basicNotifyMessageWithSSDPType(std::stringstream &msgStream, int maxAge, std::string ssdpType) const {
	// create basic message header
	msgStream << "NOTIFY * HTTP/1.1\r\n";
	msgStream << "HOST: 239.255.255.250:1900\r\n";
	msgStream << "CACHE-CONTROL: max-age=" << maxAge << "\r\n";
	msgStream << "LOCATION:" << _location << "\r\n";
	msgStream << "NTS: ssdp:" << ssdpType << "\r\n";
	msgStream << "SERVER: " << _osDescription << " UPnP/1.1 " << _productDescription << "\r\n";
}
