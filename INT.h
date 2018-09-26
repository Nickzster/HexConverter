/*
Nick Zimmermann
03 May 2017
CSIS 123A - 3488
Assignment 12 Fix (polymorphism is correctly implemented)
*/

//Integer Header file

#include <string>
#include "NUMBER.h"
using std::string;
#ifndef INT
#define INT
namespace dim
{
	//Integer class
	class integer: public Number
	{
	private:
		//10. is Not an Integer Recursive
		int recursiveNaN(string s, int count, int decimal);
	public:
		//1. Equals Functions + overloads
		void equals(int i);
		void equals(string i);
		void equals(integer i);
		///2. Mathematical Functions
		integer add(integer i);
		integer sub(integer i);
		integer mul(integer i);
		integer div(integer i);
		//3. Converts integer to int
		int toInt();
		///4. Converts integer / int to string
		//5. overloaded fxns
		integer add(int i2);
		integer sub(int i2);
		integer mul(int i2);
		integer div(int i2);
		///6. Constructors
		integer();
		integer(int i);
		integer(const integer &i);
		integer(string i);
		//7. Destructors
		~integer();
		///8. Overloaded Operators
		integer operator +(const integer &i);
		integer operator -(const integer &i);
		integer operator *(const integer &i);
		integer operator /(const integer &i);
		integer& operator = (const integer &i);
		integer& operator = (int i);
		integer& operator = (const string &i);
		bool operator == (const integer &i);
		bool operator == (int i);
		bool operator != (const integer &i);
		bool operator != (int i);
		//9. is Not an int
//		bool isNaN(string in);
		void testPrint();
	};
}
#endif