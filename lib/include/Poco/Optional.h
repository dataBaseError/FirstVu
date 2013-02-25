//
// Optional.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Optional.h#1 $
//
// Library: Foundation
// Package: Core
// Module:  Optional
//
// Definition of the Optional class template.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
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


#ifndef Foundation_Optional_INCLUDED
#define Foundation_Optional_INCLUDED


#include "Foundation.h"
#include "Exception.h"
#include <algorithm>


namespace Poco {


template <typename C>
class Optional
	/// Optional is a simple wrapper class for value types
	/// that allows to introduce a specified/unspecified state
	/// to value objects.
	///
	/// An Optional can be default constructed. In this case, 
	/// the Optional will have a Null value and isSpecified() will
	/// return false. Calling value()(without default value) on
	/// a Null object will throw a NullValueException.
	///
	/// An Optional can also be constructed from a value.
	/// It is possible to assign a value to an Optional, and
	/// to reset an Optional to contain a Null value by calling
	/// clear().
	///
	/// For use with Optional, the value type should support
	/// default construction.
	///
	/// Note that the Optional class is basically the same as
	/// Nullable. However, serializers may treat Nullable
	/// and Optional differently. An example is XML serialization based
	/// on XML Schema, where Optional would be used for an element with
	/// minOccurs == 0, whereas Nullable would be used on an element with
	/// nillable == true.
{
public:
	Optional(): 
		/// Creates an empty Optional.
		_value(),
		_isSpecified(false)
	{
	}

	Optional(const C& value): 
		/// Creates a Optional with the given value.
		_value(value), 
		_isSpecified(true)
	{
	}
	
	Optional(const Optional& other):
		/// Creates a Optional by copying another one.
		_value(other._value),
		_isSpecified(other._isSpecified)
	{
	}

	~Optional()
		/// Destroys the Optional.
	{
	}

	Optional& assign(const C& value)
		/// Assigns a value to the Optional.
	{
		_value  = value;
		_isSpecified = true;
		return *this;
	}
	
	Optional& assign(const Optional& other)
		/// Assigns another Optional.
	{
		Optional tmp(other);
		swap(tmp);
		return *this;
	}
	
	Optional& operator = (const C& value)
	{
		return assign(value);
	}

	Optional& operator = (const Optional& other)
	{
		return assign(other);
	}

	void swap(Optional& other)
	{
		std::swap(_value, other._value);
		std::swap(_isSpecified, other._isSpecified);
	}

	const C& value() const
		/// Returns the Optional's value.
		///
		/// Throws a Poco::NullValueException if the value has not been specified.
	{
		if (_isSpecified)
			return _value;
		else
			throw Poco::NullValueException();
	}

	const C& value(const C& deflt) const
		/// Returns the Optional's value, or the
		/// given default value if the Optional's 
		/// value has not been specified.
	{
		return _isSpecified ? _value : deflt;
	}

	bool isSpecified() const
		/// Returns true iff the Optional's value has been specified.
	{
		return _isSpecified;
	}
	
	void clear()
		/// Clears the Optional.
	{
		_isSpecified = false;
	}

private:
	C _value;
	bool _isSpecified;
};


template <typename C>
inline void swap(Optional<C>& n1, Optional<C>& n2)
{
	n1.swap(n2);
}


} // namespace Poco


#endif // Foundation_Optional_INCLUDED
