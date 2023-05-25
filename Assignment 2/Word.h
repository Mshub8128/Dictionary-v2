#pragma once
#ifndef WORD_H
#define WORD_H
#include <string>
#include <vector>

using namespace std;

class Word {
protected:
	string name;
	string definition;
	string wordType;
	int letterCount;
	//string letterSet;
public:
	Word(string ,string ,string);
	string getWord();
	string getDefinition();
	string getWordType();
	int	   getLetterCount();
	bool Palindrome();

	
};



#endif
