//
// Mutex_POSIX.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Mutex_POSIX.h#2 $
//
// Library: Foundation
// Package: Threading
// Module:  Mutex
//
// Definition of the MutexImpl and FastMutexImpl classes for POSIX Threads.
//
// Copyright (c) 2004-2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_Mutex_POSIX_INCLUDED
#define Foundation_Mutex_POSIX_INCLUDED


#include "Foundation.h"
#include "Exception.h"
#include <pthread.h>
#include <errno.h>


namespace Poco {


class Foundation_API MutexImpl
{
protected:
	MutexImpl();
	MutexImpl(bool fast);
	~MutexImpl();
	void lockImpl();
	bool tryLockImpl();
	bool tryLockImpl(long milliseconds);
	void unlockImpl();
	
private:
	pthread_mutex_t _mutex;
};


class Foundation_API FastMutexImpl: public MutexImpl
{
protected:
	FastMutexImpl();
	~FastMutexImpl();
};


//
// inlines
//
inline void MutexImpl::lockImpl()
{
	if (pthread_mutex_lock(&_mutex)) 
		throw SystemException("cannot lock mutex");
}


inline bool MutexImpl::tryLockImpl()
{
	int rc = pthread_mutex_trylock(&_mutex);
	if (rc == 0)
		return true;
	else if (rc == EBUSY)
		return false;
	else
		throw SystemException("cannot lock mutex");
}


inline void MutexImpl::unlockImpl()
{
	if (pthread_mutex_unlock(&_mutex))
		throw SystemException("cannot unlock mutex");
}


} // namespace Poco


#endif // Foundation_Mutex_POSIX_INCLUDED