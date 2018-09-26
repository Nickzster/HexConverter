/*
Nick Zimmermann
03 May 2017
CSIS 123A - 3488
Assignment 12 Fix (polymorphism is correctly implemented)
*/

#ifndef NUMBER
#define NUMBER
#include <iostream>
#include <string>
using std::string;
namespace dim
{
	//Number class
	class Number :public string
	{
	protected:
		string *n;
	public:
		//1. Constructors
		Number();
		Number(string n);
		void Create();
		///2. toString to convert primitative types to string
		virtual string toString();
		virtual int recursiveNaN(string s, int count, int decimal) = 0;
		bool isNaN(string s);

	};
	//Exception class
	class NumberException
	{
	private:
		int errorCode;
		string errorMessage;
	public:
		//Constructors
		NumberException() { this->errorCode = -1, this->errorMessage = "Unknown"; }
		NumberException(string errorMessage) { this->errorCode = -1, this->errorMessage = errorMessage; }
		NumberException(string errorMessage, int errorCode) { this->errorCode = errorCode, this->errorMessage = errorMessage; }
		//Functions
		string getMessage() { return this->errorMessage; }
		int getCode() { return this->errorCode; }
	};
}
#endif
