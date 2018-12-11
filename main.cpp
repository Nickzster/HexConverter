#include <iostream>
#include <sstream>
#include "Hex.h"
#include <string>
#include <sstream>
using namespace std;

// void hexToDecimal();
// void decimalToHex();

int main(int argc, char* argv[])
{
	string theArgument(argv[1]);
	if(argc < 3)
	{
		cout << "Invalid argument specified" << endl;
	}
	else if(theArgument == "add")
	{
		int sum = 0;
		for(int i = 2; i < argc; i++)
		{
			string tempstring(argv[i]);
			Hex temp(tempstring);
			sum += temp.getDecimal();
		}
		cout << "Sum in decimal: " << sum << endl;
		Hex h(sum);
		cout << "Sum in hex: " << h.getHex() << endl;
	}
	else if(theArgument == "tohex")
	{
		int number = stoi(string(argv[2]), nullptr);
		Hex temp(number);
		cout << temp.getHex() << endl;
	}
	else if(theArgument == "todecimal")
	{
	 	string tempstring(argv[2]);
		Hex temp(tempstring);
		cout << temp.getDecimal() << endl;
	}
	else
	{
		cout << "Something went wrong!" << endl;
	}
	// bool goAgain = true;
	// cout << "Hex to Decimal converter =======" << endl;
	// char choice;
	// while(goAgain)
	// {
	// 	cout << "Make a choice:" << endl;
	// 	cout << "1. Hex -> Decimal" << endl;
	// 	cout << "2. Decimal -> Hex" << endl;
	// 	cout << "q. Quit" << endl;
	// 	cout << "==> ";
	// 	cin >> choice;
	// 	switch(choice)
	// 	{
	// 	case '1':
	// 		hexToDecimal();
	// 		break;
	// 	case '2':
	// 		decimalToHex();
	// 		break;
	// 	case 'q':
	// 		goAgain = false;
	// 		break;
	// 	default:
	// 		cout << "Invalid input." << endl;
	// 	}
	// }
	return 0;
}

	// void hexToDecimal()
	// {
	// 	Hex h;
	// 	string convert;
	// 	cout << "Enter the hex to convert: ";
	// 	cin >> convert;
	// 	h.set(convert);
	// 	cout << "=-=-=-=-=-= hex(" <<convert << ") = dec(" << h.getDecimal() << ") =-=-=-=-=-=" << endl;

	// }
	// void decimalToHex()
	// {
	// 	Hex h;
	// 	int convert;
	// 	cout << "Enter the decimal to convert: ";
	// 	cin >> convert;
	// 	h.set(convert);
	// 	cout << "=-=-=-=-=-= dec(" <<convert << ") = hex(" << h.getHex() << ") =-=-=-=-=-=" << endl;

	// }