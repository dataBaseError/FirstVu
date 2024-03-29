//
// ThreadTarget.h
//
// $Id: //poco/1.4/Foundation/include/Poco/ThreadTarget.h#1 $
//
// Library: Foundation
// Package: Threading
// Module:  ThreadTarget
//
// Definition of the ThreadTarget class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_ThreadTarget_INCLUDED
#define Foundation_ThreadTarget_INCLUDED


#include "Foundation.h"
#include "Runnable.h"


namespace Poco {


class Foundation_API ThreadTarget: public Runnable
	/// This adapter simplifies using static member functions as well as 
	/// standalone functions as targets for threads.
	/// Note that it is possible to pass those entities directly to Thread::start().
	/// This adapter is provided as a convenience for higher abstraction level
	/// scenarios where Runnable abstract class is used.
	///
	/// For using a non-static member function as a thread target, please
	/// see the RunnableAdapter class.
	/// 
	/// Usage:
	///    class MyObject
	///    {
	///        static void doSomething() {}
	///    };
	///    ThreadTarget ra(&MyObject::doSomething);
	///    Thread thr;
	///    thr.start(ra);
	///
	/// or:
	/// 
	///    void doSomething() {}
	/// 
	///    ThreadTarget ra(doSomething);
	///    Thread thr;
	///    thr.start(ra);
{
public:
	typedef void (*Callback)();
	
	ThreadTarget(Callback method);
	
	ThreadTarget(const ThreadTarget& te);

	~ThreadTarget();

	ThreadTarget& operator = (const ThreadTarget& te);

	void run();
	
private:
	ThreadTarget();

	Callback _method;
};


//
// inlines
//
inline void ThreadTarget::run()
{
	_method();
}


} // namespace Poco


#endif // Foundation_ThreadTarget_INCLUDED
