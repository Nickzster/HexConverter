/*
Nick Zimmermann
03 May 2017
CSIS 123A - 3488
Assignment 12 Fix (polymorphism is correctly implemented)
*/

//Int cpp file

#include <iostream>
#include "INT.h"
#include <string>
#include <cstring>
#include <sstream>

using namespace std;
//fxns
namespace dim
{
	//1. Equals Functions + overloads

	void integer::equals(int i)
	{
		ostringstream strs;
		strs << i;
		string s = strs.str();
		*this->n = s;
	}
	void integer::equals(string i)
	{
		bool test = isNaN(i);
		//Checks to see if it is not an integer
		if (test == true)
		{
			throw NumberException("Not a valid Number");
		}
		else
		{
			*this->n = i;
		}
	}
	void integer::equals(integer i)
	{
		*this->n = i.toString();
	}

	///2. Mathematical Functions

	integer integer::add(integer i)
	{
		integer i1(*this->n), i3;
		i3 = i1.toInt() + i.toInt();
		return i3;
	}
	integer integer::sub(integer i)
	{
		integer i1(*this->n), i3;
		i3 = i1.toInt() - i.toInt();
		return i3;
	}
	integer integer::mul(integer i)
	{
		integer i1(*this->n), i3;
		i3 = i1.toInt() * i.toInt();
		return i3;
	}
	integer integer::div(integer i)
	{
		integer i1(*this->n), i3;
		i3 = i1.toInt() / i.toInt();
		return i3;
	}

	//3. Converts integer to int

	int integer::toInt()
	{
		string s = *this->n;
		int i = stod(s, nullptr);
		return i;
	}

	///4. Converts integer / int to string

	//5. overloaded fxns


	integer integer::add(int i2)
	{
		integer i3;
		integer n = *this->n;
		i3.equals(n.toInt() + i2);
		return i3;
	}

	integer integer::sub(int i2)
	{
		integer i3;
		integer n = *this->n;
		i3.equals(n.toInt() - i2);
		return i3;
	}

	integer integer::mul(int i2)
	{
		integer i3;
		integer n = *this->n;
		i3.equals(n.toInt() * i2);
		return i3;
	}

	integer integer::div(int i2)
	{
		integer i3;
		integer n = *this->n;
		i3.equals(n.toInt() / i2);
		return i3;
	}

	///6. Constructors

	integer::integer()
	{
		this->equals("0");
	}
	integer::integer(int i)
	{
		this->equals(i);
	}
	integer::integer(const integer &i)
	{
		this->equals(*i.n);
	}
	integer::integer(string i)
	{
		this->equals(i);
	}

	//7. Destructors
	integer::~integer()
	{
		delete n;
	}

	///8. Overloaded Operators

	integer integer::operator +(const integer &i)
	{
		return this->add(i);
	}
	integer integer::operator -(const integer &i)
	{
		return this->sub(i);
	}
	integer integer::operator *(const integer &i)
	{
		return this->mul(i);
	}
	integer integer::operator /(const integer &i)
	{
		return this->div(i);
	}
	integer& integer::operator = (const integer &i)
	{
		this->equals(i);
		return *this;
	}
	integer& integer::operator = (int i)
	{
		this->equals(i);
		return *this;
	}
	integer& integer::operator = (const string &i)
	{
		this->equals(i);
		return *this;
	}
	bool integer::operator == (const integer &i)
	{
		return(*this->n == *i.n);
	}
	bool integer::operator == (int i)
	{
		integer s = *this->n;
		return(s.toInt() == i);
	}
	bool integer::operator != (const integer &i)
	{
		return(*this->n != *i.n);
	}
	bool integer::operator != (int i)
	{
		integer s = *this->n;
		return(s.toInt() != i);
	}
	//9. is Not an int

/*	bool integer::isNaN(string in)
	{
		int count = recursiveNaN(in, 0, 0);
		if (count == in.size())
		{
			return false;
		}
		else
		{
			return true;
		} 
	} */


//10. is Not a Double Recursive

	int integer::recursiveNaN(string s, int count, int decimal)
	{
		//Base Case
		if (count >= s.size())
		{
			return count;
		}
		//Recursive case
		else
		{
			if (static_cast<int>(s.at(count)) >= 48 && static_cast<int>(s.at(count)) <= 57)
			{
				count++;
			}
			else
			{
				return -1;
			}
			return 0 + recursiveNaN(s, count, decimal);
		}
	}

	void integer::testPrint()
	{
		cout << *this->n << endl;
	}
}
