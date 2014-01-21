/*
 ============================================================================
 Name        : basicdevice.cpp
 Author      : Martek01
 Version     : 0.1
 Copyright   : 2014
 Description : Basic (abstract) UPnP device
 ============================================================================
 */

#include "basicdevice.h"

BasicDevice::BasicDevice(std::string urn, std::string type, std::string value) : _urn(urn), _type(type), _value(value) {

}

BasicDevice::~BasicDevice() {

}

void BasicDevice::setURN(std::string urn) {
	_urn = urn;
}

std::string BasicDevice::urn() const {
	return _urn;
}

void BasicDevice::setType(std::string type) {
	_type = type;
}

std::string BasicDevice::type() const {
	return _type;
}

void BasicDevice::setValue(std::string value) {
	_value = value;
}

std::string BasicDevice::value() const {
	return _value;
}
