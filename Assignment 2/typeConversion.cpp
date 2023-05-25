//typeConversion.cpp file
//contains two functions, conv2short(string) and conv2long(string), to convert the word types between
//abbreviations and formatted versions.
//
//Monte Shub - 17/03/2023
// 
// Function: conv2short(string)  
// Input: string as input.
// Output: string as output.
// description: input a unabbreviated, formatted version of a word type ('[noun]', '[verb]', etc) and outputs its corresponding abbreviation ('n', 'v', etc)
// functions required: <iostream>,<string>, "lowCase.h"
// 
// Function: conv2long(string)
// Input: string as input.
// Output: string as output.
// description: input a abbreviated, formatted version of a word type ('n', 'v', etc) and outputs its corresponding unabbreviated version('[noun]', '[verb]', etc)
// functions required: <iostream>,<string>, "lowCase.h"
// 
// Function: typeCheck(string) 
// Input: string as input.
// Output: string as output.
// description: function checks that the input string is a valid type of word.
// functions required: <iostream>,<string>
// 
// Function: alphaOnly(string) 
// Input: string as input.
// Output: string as output.
// description: function converts all alphabet characters in the string as "_"s
// functions required: <iostream>,<string>


#include "projLibs.h"
#include "lowCase.h"


using namespace std;
//nested array of the word types and their abbreviations
string wordTypes[2][8] = { {"[noun]","[verb]","[adverb]","[adjective]","[preposition]","[miscellaneous]","[proper noun]","[noun and verb]"},{"n","v","adv","adj","prep","misc","pn","n_and_v"} };
string typesToCheck[16] = { "noun","verb","adverb","adjective","preposition","miscellaneous","proper noun","noun and verb" , "n","v","adv","adj","prep","misc","pn","n_and_v" };

string conv2short(string typeLong) { //converts the long format text to abbreviated version
	typeLong = lowCase(typeLong);
	string shortened;
	for (int i = 0; i < 7; i++) {
		if (typeLong == wordTypes[0][i]) {
			shortened = wordTypes[1][i];
		}
		//if the input isn't in the nested array, it is saved as is.
		if (find(begin(wordTypes[0]), end(wordTypes[0]), typeLong) == end(wordTypes[0])) {
			shortened = typeLong;
		}
	}
	return shortened;//return abbreviation
}
string conv2long(string typeShort) {//abbreviated to long format conversion
	typeShort = lowCase(typeShort);
	string lengthened;
	for (int i = 0; i < 7; i++) {
		if (typeShort == wordTypes[1][i]) {
			lengthened = wordTypes[0][i];
		}
		//if input isn't in the nested array, it is saved as is.
		if (find(begin(wordTypes[1]), end(wordTypes[1]), typeShort) == end(wordTypes[1])) {
			lengthened = typeShort;
		}
	}
	return lengthened;//returns long format
}
string typeCheck(string checked) {
	if (find(begin(typesToCheck), end(typesToCheck), checked) == end(typesToCheck)) {
		return "error";
	}
	else {
		return "fine";
	}
}
string alphaOnly(string preBlank) {
	for (char& character: preBlank) {
		if (isalpha(character)) {
			character = '_';
		}
	}
	return preBlank;
}
