// wordColour.cpp file
// Holds the wordColour() function
// 
//Monte Shub - 24/04/2023
//
// Function: wordColour(int,int,int,int,string)
// input: int vert - row number of the text (rows from top),int horiz - indentation of the text (measured in characters from left), int wordNum - the word which needs to be coloured, int colourNum - the colour code of the number, string sentence - the sentence that will be split at whitespace, to have the [wordNum]th word changed colour 
// output: none
// description: Prints a sentence with the specified word coloured.
// functions required: <iostream>, <string>, <windows.h>, <sstream>

#include <iostream>
#include <string>  
#include <windows.h>
#include <sstream>
#include "wordColour.h"
using namespace std;
void wordColour(int vert, int horiz, int wordNum, int colourNum, string sentence) {
	int count = 0;
	string preColour;
	string colour;
	string postColour;
	string tempWord;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	stringstream ss;
	ss << sentence;
	while (!ss.eof()) {
		ss >> tempWord;
		count += 1;
		if (count < wordNum) {
			preColour += tempWord + " ";
		}
		if (count == wordNum) {
			colour += tempWord;
		}
		if (count > wordNum) {
			postColour += " "+ tempWord;
		}
	}
	SetConsoleTextAttribute(hConsole, 15);
	printf("\033[%d;%dH", vert, horiz);
	std::cout << preColour;
	SetConsoleTextAttribute(hConsole, colourNum);
	printf("\033[%d;%dH", vert, horiz + preColour.length());
	std::cout << colour;
	SetConsoleTextAttribute(hConsole, 15);
	printf("\033[%d;%dH", vert, horiz +preColour.length() + colour.length());
	std::cout << postColour;
}