//
// IORemoteObject.cpp
//
// Library: IoT/Devices
// Package: Generated
// Module:  IORemoteObject
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2014-2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/Devices/IORemoteObject.h"
#include "IoT/Devices/IOEventDispatcher.h"
#include "Poco/Delegate.h"
#include "Poco/RemotingNG/ORB.h"


namespace IoT {
namespace Devices {


IORemoteObject::IORemoteObject(const Poco::RemotingNG::Identifiable::ObjectId& oid, Poco::SharedPtr<IoT::Devices::IO> pServiceObject):
	IoT::Devices::IIO(),
	Poco::RemotingNG::RemoteObject(oid),
	_pServiceObject(pServiceObject)
{
	_pServiceObject->stateChanged += Poco::delegate(this, &IORemoteObject::event__stateChanged);
}


IORemoteObject::~IORemoteObject()
{
	try
	{
		_pServiceObject->stateChanged -= Poco::delegate(this, &IORemoteObject::event__stateChanged);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


void IORemoteObject::remoting__enableEvents(Poco::RemotingNG::Listener::Ptr pListener, bool enable)
{
}


void IORemoteObject::remoting__enableRemoteEvents(const std::string& protocol)
{
	Poco::RemotingNG::EventDispatcher::Ptr pEventDispatcher = new IOEventDispatcher(this, protocol);
	Poco::RemotingNG::ORB::instance().registerEventDispatcher(remoting__getURI().toString(), pEventDispatcher);
}


bool IORemoteObject::remoting__hasEvents() const
{
	return true;
}


void IORemoteObject::event__stateChanged(const bool& data)
{
	stateChanged(this, data);
}


} // namespace Devices
} // namespace IoT

