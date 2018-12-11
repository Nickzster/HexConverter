#include <iostream>
#include "Hex.h"
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
/* These functions are private. They are used to do the conversions. */
//Takes a decimal number, converts it into hex.
string Hex::toHex(int i)
{
	int temp = i; //we'll use temp for the operation.
	int mod; //stores modulus
	char c; //checks ascii value
	string check;
	string hex; //holds the hex value in reverse
	string ret; //return string
	ostringstream s; //used to convert int to string
	int count = 0;
	while (temp != 0)
	{
		mod = temp % 16;
		temp /= 16;
		if (mod >= 0 && mod <= 9)
		{
			s << mod;
			check = s.str();
			c = check.at(count);
			count++;
		}
		else
		{
			switch (mod)
			{
			case 10:
				c = 'A';
				break;
			case 11:
				c = 'B';
				break;
			case 12:
				c = 'C';
				break;
			case 13:
				c = 'D';
				break;
			case 14:
				c = 'E';
				break;
			case 15:
				c = 'F';
				break;
			}
		}
		hex += c;
	}
	//Ok, now we have the hex filled backwards. Let's reverse the order & return the hex value.
	count = hex.size() - 1;
	for (int i = 0; i < hex.size(); i++)
	{
		ret.push_back(hex.at(count));
		count--;
	}
	return ret;
}
//Takes a hex number, converts it into a decimal number.
int Hex::toDecimal(string s)
{
	string b = s; //so they are the same size. b is the backwards string.
	int count = b.size() - 1;
	char c;
	int num; //factor to multiply by
	int answer = 0;
	//reversing it in a for loop.
	for (int i = 0; i < b.size(); i++)
	{
		b.at(i) = s.at(count);
		count--;
	}
	//calculate decimal result
	for (int i = 0; i < b.size(); i++)
	{
		c = b.at(i);
		if ((int)c >= 48 && (int)c <= 57)
		{
			num = (int)c - 48;
		}
		else
		{
			switch (c)
			{
			case 'A':
				num = 10;
				break;
			case 'B':
				num = 11;
				break;
			case 'C':
				num = 12;
				break;
			case 'D':
				num = 13;
				break;
			case 'E':
				num = 14;
				break;
			case 'F':
				num = 15;
				break;
			}
		}
		answer += num * pow(16, i);
	}
	return answer;
}

/* The following functions are public.*/
//Constructors
Hex::Hex()
{
	this->decimal = 0;
	this->hex = "0";
}
Hex::Hex(int i)
{
	set(i);
}
Hex::Hex(string s)
{
	set(s);
}
//functions (getters)
int Hex::getDecimal()
{
	return this->decimal;
}
string Hex::getHex()
{
	return this->hex;
}
//functions (setters)
void Hex::set(string s)
{
	this->hex = s;
	this->decimal = toDecimal(s);
}
void Hex::set(int i)
{
	this->decimal = i;
	this->hex = toHex(i);
}