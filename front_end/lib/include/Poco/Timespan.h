//
// Timespan.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Timespan.h#1 $
//
// Library: Foundation
// Package: DateTime
// Module:  Timespan
//
// Definition of the Timespan class.
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


#ifndef Foundation_Timespan_INCLUDED
#define Foundation_Timespan_INCLUDED


#include "Foundation.h"
#include "Timestamp.h"


namespace Poco {


class Foundation_API Timespan
	/// A class that represents time spans up to microsecond resolution.
{
public:
	typedef Timestamp::TimeDiff TimeDiff;

	Timespan();
		/// Creates a zero Timespan.
		
	Timespan(TimeDiff microseconds);
		/// Creates a Timespan.
	
	Timespan(long seconds, long microseconds);
		/// Creates a Timespan. Useful for creating
		/// a Timespan from a struct timeval.
	
	Timespan(int days, int hours, int minutes, int seconds, int microseconds);
		/// Creates a Timespan.

	Timespan(const Timespan& timespan);
		/// Creates a Timespan from another one.

	~Timespan();
		/// Destroys the Timespan.

	Timespan& operator = (const Timespan& timespan);
		/// Assignment operator.

	Timespan& operator = (TimeDiff microseconds);
		/// Assignment operator.
		
	Timespan& assign(int days, int hours, int minutes, int seconds, int microseconds);
		/// Assigns a new span.
		
	Timespan& assign(long seconds, long microseconds);
		/// Assigns a new span. Useful for assigning
		/// from a struct timeval.

	void swap(Timespan& timespan);
		/// Swaps the Timespan with another one.

	bool operator == (const Timespan& ts) const;
	bool operator != (const Timespan& ts) const;
	bool operator >  (const Timespan& ts) const;
	bool operator >= (const Timespan& ts) const;
	bool operator <  (const Timespan& ts) const;
	bool operator <= (const Timespan& ts) const;

	bool operator == (TimeDiff microseconds) const;
	bool operator != (TimeDiff microseconds) const;
	bool operator >  (TimeDiff microseconds) const;
	bool operator >= (TimeDiff microseconds) const;
	bool operator <  (TimeDiff microseconds) const;
	bool operator <= (TimeDiff microseconds) const;
	
	Timespan operator + (const Timespan& d) const;
	Timespan operator - (const Timespan& d) const;
	Timespan& operator += (const Timespan& d);
	Timespan& operator -= (const Timespan& d);

	Timespan operator + (TimeDiff microseconds) const;
	Timespan operator - (TimeDiff microseconds) const;
	Timespan& operator += (TimeDiff microseconds);
	Timespan& operator -= (TimeDiff microseconds);

	int days() const;
		/// Returns the number of days.
		
	int hours() const;
		/// Returns the number of hours (0 to 23).
		
	int totalHours() const;
		/// Returns the total number of hours.
		
	int minutes() const;
		/// Returns the number of minutes (0 to 59).
		
	int totalMinutes() const;
		/// Returns the total number of minutes.
		
	int seconds() const;
		/// Returns the number of seconds (0 to 59).
		
	int totalSeconds() const;
		/// Returns the total number of seconds.
		
	int milliseconds() const;
		/// Returns the number of milliseconds (0 to 999).
		
	TimeDiff totalMilliseconds() const;
		/// Returns the total number of milliseconds.
		
	int microseconds() const;
		/// Returns the fractions of a millisecond
		/// in microseconds (0 to 999).
		
	int useconds() const;
		/// Returns the fractions of a second
		/// in microseconds (0 to 999999).
		
	TimeDiff totalMicroseconds() const;
		/// Returns the total number of microseconds.

	static const TimeDiff MILLISECONDS; /// The number of microseconds in a millisecond.
	static const TimeDiff SECONDS;      /// The number of microseconds in a second.
	static const TimeDiff MINUTES;      /// The number of microseconds in a minute.
	static const TimeDiff HOURS;        /// The number of microseconds in a hour.
	static const TimeDiff DAYS;         /// The number of microseconds in a day.

private:
	TimeDiff _span;
};


//
// inlines
//
inline int Timespan::days() const
{
	return int(_span/DAYS);
}


inline int Timespan::hours() const
{
	return int((_span/HOURS) % 24);
}

	
inline int Timespan::totalHours() const
{
	return int(_span/HOURS);
}

	
inline int Timespan::minutes() const
{
	return int((_span/MINUTES) % 60);
}

	
inline int Timespan::totalMinutes() const
{
	return int(_span/MINUTES);
}

	
inline int Timespan::seconds() const
{
	return int((_span/SECONDS) % 60);
}

	
inline int Timespan::totalSeconds() const
{
	return int(_span/SECONDS);
}

	
inline int Timespan::milliseconds() const
{
	return int((_span/MILLISECONDS) % 1000);
}

	
inline Timespan::TimeDiff Timespan::totalMilliseconds() const
{
	return _span/MILLISECONDS;
}

	
inline int Timespan::microseconds() const
{
	return int(_span % 1000);
}


inline int Timespan::useconds() const
{
	return int(_span % 1000000);
}

	
inline Timespan::TimeDiff Timespan::totalMicroseconds() const
{
	return _span;
}


inline bool Timespan::operator == (const Timespan& ts) const
{
	return _span == ts._span;
}


inline bool Timespan::operator != (const Timespan& ts) const
{
	return _span != ts._span;
}


inline bool Timespan::operator >  (const Timespan& ts) const
{
	return _span > ts._span;
}


inline bool Timespan::operator >= (const Timespan& ts) const
{
	return _span >= ts._span;
}


inline bool Timespan::operator <  (const Timespan& ts) const
{
	return _span < ts._span;
}


inline bool Timespan::operator <= (const Timespan& ts) const
{
	return _span <= ts._span;
}


inline bool Timespan::operator == (TimeDiff microseconds) const
{
	return _span == microseconds;
}


inline bool Timespan::operator != (TimeDiff microseconds) const
{
	return _span != microseconds;
}


inline bool Timespan::operator >  (TimeDiff microseconds) const
{
	return _span > microseconds;
}


inline bool Timespan::operator >= (TimeDiff microseconds) const
{
	return _span >= microseconds;
}


inline bool Timespan::operator <  (TimeDiff microseconds) const
{
	return _span < microseconds;
}


inline bool Timespan::operator <= (TimeDiff microseconds) const
{
	return _span <= microseconds;
}


inline void swap(Timespan& s1, Timespan& s2)
{
	s1.swap(s2);
}


} // namespace Poco


#endif // Foundation_Timespan_INCLUDED
