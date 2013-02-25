//
// Delegate.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Delegate.h#5 $
//
// Library: Foundation
// Package: Events
// Module:  Delegate
//
// Implementation of the Delegate template.
//
// Copyright (c) 2006-2011, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_Delegate_INCLUDED
#define Foundation_Delegate_INCLUDED


#include "Foundation.h"
#include "AbstractDelegate.h"
#include "FunctionDelegate.h"
#include "Expire.h"
#include "Mutex.h"


namespace Poco {


template <class TObj, class TArgs, bool withSender = true> 
class Delegate: public AbstractDelegate<TArgs>
{
public:
	typedef void (TObj::*NotifyMethod)(const void*, TArgs&);

	Delegate(TObj* obj, NotifyMethod method):
		_receiverObject(obj), 
		_receiverMethod(method)
	{
	}

	Delegate(const Delegate& delegate):
		AbstractDelegate<TArgs>(delegate),
		_receiverObject(delegate._receiverObject),
		_receiverMethod(delegate._receiverMethod)
	{
	}

	~Delegate()
	{
	}
	
	Delegate& operator = (const Delegate& delegate)
	{
		if (&delegate != this)
		{
			this->_receiverObject = delegate._receiverObject;
			this->_receiverMethod = delegate._receiverMethod;
		}
		return *this;
	}

	bool notify(const void* sender, TArgs& arguments)
	{
		Mutex::ScopedLock lock(_mutex);
		if (_receiverObject)
		{
			(_receiverObject->*_receiverMethod)(sender, arguments);
			return true;
		}
		else return false;
	}

	bool equals(const AbstractDelegate<TArgs>& other) const
	{
		const Delegate* pOtherDelegate = reinterpret_cast<const Delegate*>(other.unwrap());
		return pOtherDelegate && _receiverObject == pOtherDelegate->_receiverObject && _receiverMethod == pOtherDelegate->_receiverMethod;
	}

	AbstractDelegate<TArgs>* clone() const
	{
		return new Delegate(*this);
	}
	
	void disable()
	{
		Mutex::ScopedLock lock(_mutex);
		_receiverObject = 0;
	}

protected:
	TObj*        _receiverObject;
	NotifyMethod _receiverMethod;
	Mutex        _mutex;

private:
	Delegate();
};


template <class TObj, class TArgs> 
class Delegate<TObj, TArgs, false>: public AbstractDelegate<TArgs>
{
public:
	typedef void (TObj::*NotifyMethod)(TArgs&);

	Delegate(TObj* obj, NotifyMethod method):
		_receiverObject(obj), 
		_receiverMethod(method)
	{
	}

	Delegate(const Delegate& delegate):
		AbstractDelegate<TArgs>(delegate),
		_receiverObject(delegate._receiverObject),
		_receiverMethod(delegate._receiverMethod)
	{
	}

	~Delegate()
	{
	}
	
	Delegate& operator = (const Delegate& delegate)
	{
		if (&delegate != this)
		{
			this->_pTarget        = delegate._pTarget;
			this->_receiverObject = delegate._receiverObject;
			this->_receiverMethod = delegate._receiverMethod;
		}
		return *this;
	}

	bool notify(const void*, TArgs& arguments)
	{
		Mutex::ScopedLock lock(_mutex);
		if (_receiverObject)
		{
			(_receiverObject->*_receiverMethod)(arguments);
			return true;
		}
		else return false;
	}

	bool equals(const AbstractDelegate<TArgs>& other) const
	{
		const Delegate* pOtherDelegate = reinterpret_cast<const Delegate*>(other.unwrap());
		return pOtherDelegate && _receiverObject == pOtherDelegate->_receiverObject && _receiverMethod == pOtherDelegate->_receiverMethod;
	}

	AbstractDelegate<TArgs>* clone() const
	{
		return new Delegate(*this);
	}
	
	void disable()
	{
		Mutex::ScopedLock lock(_mutex);
		_receiverObject = 0;
	}

protected:
	TObj*        _receiverObject;
	NotifyMethod _receiverMethod;
	Mutex        _mutex;

private:
	Delegate();
};


template <class TObj, class TArgs>
static Delegate<TObj, TArgs, true> delegate(TObj* pObj, void (TObj::*NotifyMethod)(const void*, TArgs&))
{
	return Delegate<TObj, TArgs, true>(pObj, NotifyMethod);
}


template <class TObj, class TArgs>
static Delegate<TObj, TArgs, false> delegate(TObj* pObj, void (TObj::*NotifyMethod)(TArgs&))
{
	return Delegate<TObj, TArgs, false>(pObj, NotifyMethod);
}


template <class TObj, class TArgs>
static Expire<TArgs> delegate(TObj* pObj, void (TObj::*NotifyMethod)(const void*, TArgs&), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<TArgs>(Delegate<TObj, TArgs, true>(pObj, NotifyMethod), expireMillisecs);
}


template <class TObj, class TArgs>
static Expire<TArgs> delegate(TObj* pObj, void (TObj::*NotifyMethod)(TArgs&), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<TArgs>(Delegate<TObj, TArgs, false>(pObj, NotifyMethod), expireMillisecs);
}


template <class TArgs>
static Expire<TArgs> delegate(void (*NotifyMethod)(const void*, TArgs&), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<TArgs>(FunctionDelegate<TArgs, true, true>(NotifyMethod), expireMillisecs);
}


template <class TArgs>
static Expire<TArgs> delegate(void (*NotifyMethod)(void*, TArgs&), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<TArgs>(FunctionDelegate<TArgs, true, false>(NotifyMethod), expireMillisecs);
}


template <class TArgs>
static Expire<TArgs> delegate(void (*NotifyMethod)(TArgs&), Timestamp::TimeDiff expireMillisecs)
{
	return Expire<TArgs>(FunctionDelegate<TArgs, false>(NotifyMethod), expireMillisecs);
}


template <class TArgs>
static FunctionDelegate<TArgs, true, true> delegate(void (*NotifyMethod)(const void*, TArgs&))
{
	return FunctionDelegate<TArgs, true, true>(NotifyMethod);
}


template <class TArgs>
static FunctionDelegate<TArgs, true, false> delegate(void (*NotifyMethod)(void*, TArgs&))
{
	return FunctionDelegate<TArgs, true, false>(NotifyMethod);
}


template <class TArgs>
static FunctionDelegate<TArgs, false> delegate(void (*NotifyMethod)(TArgs&))
{
	return FunctionDelegate<TArgs, false>(NotifyMethod);
}


} // namespace Poco


#endif // Foundation_Delegate_INCLUDED
