// SlowText.cpp file
// This contains the slowText(string, int, int, int) function
//  
// Monte Shub - 10/03/2023
//
// Function: slowText(string word, int vert, int horiz, int time);
// input: string for display, int for rows from top of console, int for indentation from left (in letters), int for time in ms
// output: none
// description: prints the string letter by letter, with int time pause in between each. (used for visuals only.)
// functions required: <iostream>, <string>, <fstream>, <stdlib.h>, <chrono>, <thread>


#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     
#include <chrono>       
#include <thread>   
#include "SlowText.h"
using namespace std;

void slowText(string word, int vert, int horiz, int time) {

	int lettertime = time;
	int textRow = vert;
	int textCol = horiz;
	string toSlow = word;

	for (int i = 0; i < toSlow.size(); i++) {
		printf("\033[%d;%dH", textRow, textCol + i);
		cout << toSlow[i];
		this_thread::sleep_for(chrono::milliseconds(lettertime));
	}
}