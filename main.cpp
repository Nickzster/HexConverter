#include <iostream>
#include <sstream>
#include "Hex.h"
using namespace std;

void hexToDecimal();
void decimalToHex();

int main()
{
	bool goAgain = true;
	cout << "Hex to Decimal converter =======" << endl;
	char choice;
	while(goAgain)
	{
		cout << "Make a choice:" << endl;
		cout << "1. Hex -> Decimal" << endl;
		cout << "2. Decimal -> Hex" << endl;
		cout << "q. Quit" << endl;
		cout << "==> ";
		cin >> choice;
		switch(choice)
		{
		case '1':
			hexToDecimal();
			break;
		case '2':
			decimalToHex();
			break;
		case 'q':
			goAgain = false;
			break;
		default:
			cout << "Invalid input." << endl;
		}
	}
	return 0;
}

	void hexToDecimal()
	{
		Hex h;
		string convert;
		cout << "Enter the hex to convert: ";
		cin >> convert;
		h.set(convert);
		cout << "=-=-=-=-=-= hex(" <<convert << ") = dec(" << h.getDecimal() << ") =-=-=-=-=-=" << endl;

	}
	void decimalToHex()
	{
		Hex h;
		int convert;
		cout << "Enter the decimal to convert: ";
		cin >> convert;
		h.set(convert);
		cout << "=-=-=-=-=-= dec(" <<convert << ") = hex(" << h.getHex() << ") =-=-=-=-=-=" << endl;

	}