//
// RWLock.h
//
// $Id: //poco/1.4/Foundation/include/Poco/RWLock.h#3 $
//
// Library: Foundation
// Package: Threading
// Module:  RWLock
//
// Definition of the RWLock class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_RWLock_INCLUDED
#define Foundation_RWLock_INCLUDED


#include "Foundation.h"
#include "Exception.h"


#if defined(POCO_OS_FAMILY_WINDOWS)
#if defined(_WIN32_WCE)
#include "RWLock_WINCE.h"
#else
#include "RWLock_WIN32.h"
#endif
#elif defined(POCO_ANDROID)
#include "RWLock_Android.h"
#elif defined(POCO_VXWORKS)
#include "RWLock_VX.h"
#else
#include "RWLock_POSIX.h"
#endif


namespace Poco {


class ScopedRWLock;
class ScopedReadRWLock;
class ScopedWriteRWLock;


class Foundation_API RWLock: private RWLockImpl
	/// A reader writer lock allows multiple concurrent
	/// readers or one exclusive writer.
{
public:
	typedef ScopedRWLock ScopedLock;
	typedef ScopedReadRWLock ScopedReadLock;
	typedef ScopedWriteRWLock ScopedWriteLock;

	RWLock();
		/// Creates the Reader/Writer lock.
		
	~RWLock();
		/// Destroys the Reader/Writer lock.
	
	void readLock();
		/// Acquires a read lock. If another thread currently holds a write lock,
		/// waits until the write lock is released.

	bool tryReadLock();
		/// Tries to acquire a read lock. Immediately returns true if successful, or
		/// false if another thread currently holds a write lock.

	void writeLock();
		/// Acquires a write lock. If one or more other threads currently hold 
		/// locks, waits until all locks are released. The results are undefined
		/// if the same thread already holds a read or write lock

	bool tryWriteLock();
		/// Tries to acquire a write lock. Immediately returns true if successful,
		/// or false if one or more other threads currently hold 
		/// locks. The result is undefined if the same thread already
		/// holds a read or write lock.

	void unlock();
		/// Releases the read or write lock.

private:
	RWLock(const RWLock&);
	RWLock& operator = (const RWLock&);
};


class Foundation_API ScopedRWLock
	/// A variant of ScopedLock for reader/writer locks.
{
public:
	ScopedRWLock(RWLock& rwl, bool write = false);
	~ScopedRWLock();

private:
	RWLock& _rwl;

	ScopedRWLock();
	ScopedRWLock(const ScopedRWLock&);
	ScopedRWLock& operator = (const ScopedRWLock&);
};


class Foundation_API ScopedReadRWLock : public ScopedRWLock
	/// A variant of ScopedLock for reader locks.
{
public:
	ScopedReadRWLock(RWLock& rwl);
	~ScopedReadRWLock();
};


class Foundation_API ScopedWriteRWLock : public ScopedRWLock
	/// A variant of ScopedLock for writer locks.
{
public:
	ScopedWriteRWLock(RWLock& rwl);
	~ScopedWriteRWLock();
};


//
// inlines
//
inline void RWLock::readLock()
{
	readLockImpl();
}


inline bool RWLock::tryReadLock()
{
	return tryReadLockImpl();
}


inline void RWLock::writeLock()
{
	writeLockImpl();
}


inline bool RWLock::tryWriteLock()
{
	return tryWriteLockImpl();
}


inline void RWLock::unlock()
{
	unlockImpl();
}


inline ScopedRWLock::ScopedRWLock(RWLock& rwl, bool write): _rwl(rwl)
{
	if (write)
		_rwl.writeLock();
	else
		_rwl.readLock();
}


inline ScopedRWLock::~ScopedRWLock()
{
	_rwl.unlock();
}


inline ScopedReadRWLock::ScopedReadRWLock(RWLock& rwl): ScopedRWLock(rwl, false)
{
}


inline ScopedReadRWLock::~ScopedReadRWLock()
{
}


inline ScopedWriteRWLock::ScopedWriteRWLock(RWLock& rwl): ScopedRWLock(rwl, true)
{
}


inline ScopedWriteRWLock::~ScopedWriteRWLock()
{
}


} // namespace Poco


#endif // Foundation_RWLock_INCLUDED
