/*
Nick Zimmermann
03 May 2017
CSIS 123A - 3488
Assignment 12 Fix (polymorphism is correctly implemented)
*/

#include <iostream>
#include <string>
#include <sstream>
#include "NUMBER.h"
using namespace std;
//1. Constructors
namespace dim
{
	Number::Number()
	{
		Create();
		*this->n = "0";
	}

	Number::Number(string n)
	{
		Create();
		*this->n = n;
	}
	void Number::Create()
	{
		this->n = new string;
	}

	///2. "toString" Function (converts primitative type to string)

	string Number::toString()
	{
		ostringstream strs;
		string str;
		strs << *this->n;
		str = strs.str();
		return str;
	}

	//3. isNaN function in Number

	bool Number::isNaN(string s)
	{
		if (recursiveNaN(s, 0, 0) == s.size())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}