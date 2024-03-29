//
// PriorityStrategy.h
//
// $Id: //poco/1.4/Foundation/include/Poco/PriorityStrategy.h#2 $
//
// Library: Foundation
// Package: Events
// Module:  PrioritytStrategy
//
// Implementation of the DefaultStrategy template.
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


#ifndef Foundation_PriorityStrategy_INCLUDED
#define Foundation_PriorityStrategy_INCLUDED


#include "NotificationStrategy.h"
#include "SharedPtr.h"
#include <vector>


namespace Poco {


template <class TArgs, class TDelegate> 
class PriorityStrategy: public NotificationStrategy<TArgs, TDelegate>
	/// NotificationStrategy for PriorityEvent.
	///
	/// Delegates are kept in a std::vector<>, ordered
	/// by their priority.
{
public:
	typedef SharedPtr<TDelegate>         DelegatePtr;
	typedef std::vector<DelegatePtr>     Delegates;
	typedef typename Delegates::iterator Iterator;

public:
	PriorityStrategy()
	{
	}

	PriorityStrategy(const PriorityStrategy& s):
		_delegates(s._delegates)
	{
	}

	~PriorityStrategy()
	{
	}

	void notify(const void* sender, TArgs& arguments)
	{
		for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
		{
			(*it)->notify(sender, arguments);
		}
	}

	void add(const TDelegate& delegate)
	{
		for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
		{
			if ((*it)->priority() > delegate.priority())
			{
				_delegates.insert(it, DelegatePtr(static_cast<TDelegate*>(delegate.clone())));
				return;
			}
		}
		_delegates.push_back(DelegatePtr(static_cast<TDelegate*>(delegate.clone())));
	}

	void remove(const TDelegate& delegate)
	{
		for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
		{
			if (delegate.equals(**it))
			{
				(*it)->disable();
				_delegates.erase(it);
				return;
			}
		}
	}

	PriorityStrategy& operator = (const PriorityStrategy& s)
	{
		if (this != &s)
		{
			_delegates = s._delegates;
		}
		return *this;
	}

	void clear()
	{
		for (Iterator it = _delegates.begin(); it != _delegates.end(); ++it)
		{
			(*it)->disable();
		}
		_delegates.clear();
	}

	bool empty() const
	{
		return _delegates.empty();
	}

protected:
	Delegates _delegates;
};


} // namespace Poco


#endif // Foundation_PriorityStrategy_INCLUDED
