#pragma once
#ifndef EXTENDEDDICTIONARY_H
#define EXTENDEDDICTIONARY_H
#include "Dictionary.h"

class ExtendedDictionary : public Dictionary {
private:
	vector<Word*> PalindromeWords;
	int gameloses;
	int gamesPlayed;
public:
	int yourScore;
	int highScore;
	bool playTitle;
	int Audio;
	bool loadDefault;
	void setTitle();
	void showPalindrome();
	void findRhymes(string);
	void guessingGame();
	string definitionBlanker();
	void setDefault();
	void loadSettings();
	void saveSettings();
	void cheatle();
	void AudioToggle();

};




#endif // !EXTENDEDDICTIONARY_H
