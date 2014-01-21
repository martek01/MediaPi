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

#include "basicdevice.h"
#include "multicastsender.h"

#include <sstream>

#include <iostream>

RootDevice::RootDevice(boost::asio::io_service &ioService, std::string uuid) : _multicastSender(ioService), _uuid(uuid) {

}

RootDevice::~RootDevice() {
	
}

void RootDevice::sendDeviceAvailable(int maxAge) {
	// create additional header
	std::stringstream msgStream;
	
	msgStream << "CACHE-CONTROL: max-age=" << maxAge << "\r\n";
	msgStream << "LOCATION: " << _location << "\r\n";
	msgStream << "SERVER: " << _osDescription << " UPnP/1.1 " << _productDescription << "\r\n";
	//msgStream << "BOOTID.UPNP.ORG: 0\r\n";
	//msgStream << "CONFIGID.UPNP.ORG: \r\n";
	//msgStream << "SEARCHPORT.UPNP.ORG: \r\n\r\n";
	
	// send multicast notify
	sendNotify("alive", msgStream.str());
}

void RootDevice::sendDeviceUnavailable() {
	// create additional header
	std::stringstream msgStream;
	
	//msgStream << "BOOTID.UPNP.ORG: 0\r\n";
	//msgStream << "CONFIGID.UPNP.ORG: \r\n";
	
	// send multicast notify
	sendNotify("alive", msgStream.str());
}

void RootDevice::sendDeviceUpdate() {
	// create additional header
	std::stringstream msgStream;
	
	msgStream << "LOCATION: " << _location << "\r\n";
	//msgStream << "BOOTID.UPNP.ORG: 0\r\n";
	//msgStream << "CONFIGID.UPNP.ORG: \r\n";
	//msgStream << "NEXTBOODID.UPNP.ORG: \r\n";
	//msgStream << "SEARCHPORT.UPNP.ORG: \r\n\r\n";
	
	// send multicast notify
	sendNotify("alive", msgStream.str());
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

void RootDevice::addDevice(BasicDevice *device) {
	// add to devices list
	_devices.push_back(device);
}

void RootDevice::removeDevice(BasicDevice *device) {
	// remove from devices list
	for (std::vector<BasicDevice *>::iterator it = _devices.begin(); it != _devices.end(); it++) {
		if (*it == device) {
			_devices.erase(it);
		}
	}
}

void RootDevice::sendNotify(std::string ssdpType, std::string additionalHeader) {
	// create message header
	std::stringstream msgStream;
	std::string message, basicMessage;
	
	msgStream << "NOTIFY * HTTP/1.1\r\n";
	msgStream << "HOST: 239.255.255.250:1900\r\n";
	msgStream << "NTS: ssdp:" << ssdpType << "\r\n";
	msgStream << additionalHeader;
	
	basicMessage = msgStream.str();
	
	// send root message
	message = basicMessage;
	message += "NT: upnp:rootdevice\r\n";
	message += "USN: uuid:" + _uuid + "::upnp:rootdevice\r\n";
	message += "\r\n";
	
	_multicastSender.sendMessage(message);
	
	// send root device message
	message = basicMessage;
	message += "NT: uuid:" + _uuid + "\r\n";
	message += "USN: uuid:" + _uuid + "\r\n";
	message += "\r\n";
	
	_multicastSender.sendMessage(message);
	
	// send devices messages
	for (std::vector<BasicDevice *>::iterator it = _devices.begin(); it != _devices.end(); it++) {
		// get device
		BasicDevice *device = *it;
	
		// generate message
		message = basicMessage;
		message += "NT: urn:" + device->urn() + ":" + device->type() + ":" + device->value() + ":1\r\n";
		message += "USN: uuid:" + _uuid + "::urn:" + device->urn() + ":" + device->type() + ":" + device->value() + ":1\r\n";;
		message += "\r\n";
		
		// send message
		_multicastSender.sendMessage(message);
	}
}
