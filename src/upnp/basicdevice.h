/*
 ============================================================================
 Name        : basicdevice.h
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Basic (abstract) UPnP device
 ============================================================================
 */
 
#ifndef BASIC_DEVICE_H
#define BASIC_DEVICE_H

#include <string>

// UPnP basic (abstract) device
class BasicDevice {
private:
	// uniform resource name for UPnP
	std::string _urn;
	
	// type name for UPnP
	std::string _type;
	
	// type value for UPnP
	std::string _value;

public:
	// create basic device with urn and service name
	BasicDevice(std::string urn, std::string type, std::string value);
	
	// destroy basic device
	virtual ~BasicDevice();
	
	// set new uniform resource name 
	void setURN(std::string urn);
	
	// get uniform resource name
	std::string urn() const;
	
	// set new type name
	void setType(std::string type);
	
	// get type name
	std::string type() const;
	
	// set new type value 
	void setValue(std::string value);
	
	// get type value
	std::string value() const;
};

#endif /* BASIC_DEVICE_H */