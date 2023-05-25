//lowCase.cpp file
//simple function for converting a string to all lower case.
//
//Monte Shub - 17/03/2023
// Functions: lowCase()
// Input: string as input.
// Output: string as output.
// description: It simply receives a string of letters (upper case, lower case, or mixed) as input, and outputs an entirely lowercase
//version of the same string. It accepts white space.
//functions required: <cctype>,<cstring>,<string>,<iostream>

#include "projLibs.h"
#include <cctype>
#include <cstring>
#include "lowCase.h"
using namespace std;

string lowCase(string inputText) {
	string textLow;
	for (int i = 0; i < inputText.size(); i++) {
		textLow.push_back(tolower(inputText[i]));
	}
	return textLow;
}