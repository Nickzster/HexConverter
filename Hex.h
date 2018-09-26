#include <iostream>
using std::string;
#ifndef HEX
#define HEX
class Hex
{
private:
	//data members
	int decimal;
	string hex;
	//conversion functions
	string toHex(int i);
	int toDecimal(string s);
public:
	//constructors
	Hex();
	Hex(int i);
	Hex(string s);
	//functions (getters)
	int getDecimal();
	string getHex();
	//functions (setters)
	void set(string s);
	void set(int i);
	//arithematic functions

};
#endif
