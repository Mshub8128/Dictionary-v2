//Word.cpp
// Contains implementation of Word class.
//
//Monte Shub - 17/03/2023
//
// Function: Word(string nameAdd, string definitionAdd, string wordTypeAdd)
// Input:word string, definition string, word type string
// Output: None
// Description: Acts as a default constructor for the Word class
// required functions: "Word.h",<iostream>, <string>
//  
// Function: getWord()
// Input: None (Requires that a word-class object)
// Output: string name part of word-class object
// description:returns name part of a word-class object
// required functions: "Word.h",<iostream>, <string>
//  
// Function: getDefinition()
// Input: None (Requires that a word-class object)
// Output: string definition of word-class object.
// description: returns definition of a  word-class object.
// required functions: "Word.h",<iostream>, <string>
// 
// Function: getWordType()
// Input: None (Requires that a word-class object)
// Output: string word type of word-class object.
// description: returns word type.of a word-class object.
// required functions: "Word.h",<iostream>, <string>
// 
// Function:getLetterCount()
// Input:None(Requires that a word-class object)
// Output: int number of letters in the name part of a word-class object.
// description: returns word length of a word-class object.
// required functions: "Word.h",<iostream>, <string>
// 
// Function: Palindrome()
// Input: None (Requires that a word-class object)
// Output: Returns whether a word is a palindrome or not
// description: For a given word, determines if it is a palindrome or not.
// required functions: "Word.h",<iostream>, <string>


#include "projLibs.h"
#include "Word.h"
#include "Dictionary.h"
using namespace std;

Word::Word(string nameAdd, string definitionAdd, string wordTypeAdd) {
	name = nameAdd;
	definition = definitionAdd;
	wordType = wordTypeAdd;
}
string Word::getWord() {
	return name;
}
string Word::getDefinition() {
	return definition;
}
string Word::getWordType() {
	return wordType;
}
int Word::getLetterCount() {
	int count = 0;
	for (int i = 0; i < name.length(); i++) {
		count += 1;
	}
	letterCount = count;
	return letterCount;
}
bool Word::Palindrome() {
	for (int i = 0; i < name.length(); i++) {
		if (name.length() > 1) {
			if (name[i] != name[name.length() - i - 1]) {
				return false;
			}
		}
	}
	if (name.length() == 1) {
		return false;
	}
	return true;
}

