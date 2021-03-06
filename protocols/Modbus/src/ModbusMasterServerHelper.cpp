//
// ModbusMasterServerHelper.cpp
//
// Library: IoT/Modbus
// Package: Generated
// Module:  ModbusMasterServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/Modbus/ModbusMasterServerHelper.h"
#include "IoT/Modbus/ModbusMasterEventDispatcher.h"
#include "IoT/Modbus/ModbusMasterSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace IoT {
namespace Modbus {


namespace
{
	static Poco::SingletonHolder<ModbusMasterServerHelper> shModbusMasterServerHelper;
}


ModbusMasterServerHelper::ModbusMasterServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	_pORB->registerSkeleton("ModbusMaster", new ModbusMasterSkeleton);
}


ModbusMasterServerHelper::~ModbusMasterServerHelper()
{
	try
	{
		_pORB->unregisterSkeleton("ModbusMaster", true);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


std::string ModbusMasterServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Modbus::ModbusMasterRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return ModbusMasterServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


Poco::AutoPtr<IoT::Modbus::ModbusMasterRemoteObject> ModbusMasterServerHelper::createRemoteObjectImpl(Poco::SharedPtr<IoT::Modbus::ModbusMaster> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new ModbusMasterRemoteObject(oid, pServiceObject);
}


void ModbusMasterServerHelper::enableEventsImpl(const std::string& uri, const std::string& protocol)
{
	Poco::RemotingNG::Identifiable::Ptr pIdentifiable = _pORB->findObject(uri);
	Poco::AutoPtr<ModbusMasterRemoteObject> pRemoteObject = pIdentifiable.cast<ModbusMasterRemoteObject>();
	if (pRemoteObject)
	{
		pRemoteObject->remoting__enableRemoteEvents(protocol);
	}
	else throw Poco::NotFoundException("remote object", uri);
}


ModbusMasterServerHelper& ModbusMasterServerHelper::instance()
{
	return *shModbusMasterServerHelper.get();
}


std::string ModbusMasterServerHelper::registerObjectImpl(Poco::AutoPtr<IoT::Modbus::ModbusMasterRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void ModbusMasterServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


} // namespace Modbus
} // namespace IoT

