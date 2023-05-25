#pragma once
#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <vector>
#include "Word.h"
using namespace std;

class Dictionary {
private:
	vector<Word*> wordsWithRepeatChar;
	char searchChar;
protected:
	vector<Word*> words;
public:
	Word* addWord(string nameAdd, string definitionAdd, string wordTypeadd);
	Word* addMultiCharWord(string nameAdd, string definitionAdd, string wordTypeadd);
	void loadDict(int sound);
	Word* searchWord(string);
	void brandNewEntry(int sound);
	Word* listAllWords();
	void MultiCharWordLoader(int sound);
	bool dictLoaded;
	void loadDefaultDict();

};
#endif 