// ExtendedDictionary.cpp file
// This contains the implementation of the ExtendedDictionary class.
// 
//Monte Shub - 15/03/2023
//
// Function: loadDict()
// Input: None
// Output: None
// description: Prompts the user to select a dictionary .txt file, and loads it into the program as a vector.
// required functions: "Word.h",<iostream>,<string>,<vector>,<fstream>
// 
// Function: addWord(string nameAdd, string definitionAdd, string wordTypeadd)
// Input: string nameAdd, string definitionAdd, string wordTypeadd (The name, definition, and word type of a new entry in the dictionary.)
// Output: None
// description: Used to add a new word to the dictionary.
// required functions: "Word.h",<iostream>,<string>,<vector>
//
// Function: addMultiCharWord(string nameAdd, string definitionAdd, string wordTypeadd)
// Input: string nameAdd, string definitionAdd, string wordTypeadd (The name, definition, and word type of a new entry in the dictionary.)
// Output: None
// description: Used to add a new word to the multicharacter dictionary. (used conditionally) 
// required functions: "Word.h",<iostream>,<string>,<vector>
//
// Function: listAllWords()
// Input: None
// Output: None 
// description: Lists all words within the main dictionary.
// required functions: "Word.h",<iostream>,<string>,<vector>
// 
// Function: searchWord(string nameIn)
// Input: string nameIn. (the name part of the word to search in the dictionary.)
// Output: Either the name part of the word, or NULL.
// description: Checks whether the dictionary contains "nameIn" (lower case). If it does, it returns the word. If not, returns NULL.
// required functions: "Word.h",<iostream>,<string>,<vector>,"lowCase.h"
//
// Function: brandNewEntry()
// Input: None
// Output: None
// description: Prompts the user to create a new word/definition/word type. Normalizes it so that it is the same format required for the dictionary file. Also offers to save the dictionary to a new filepath. 
// required functions: "Word.h",<iostream>,<string>,<vector>,<fstream>, "lowCase.h"
//
// Function: MultiCharWordLoader()
// Input: None
// Output: None 
// description: Prompts the user to input a string containing a single character. It then prints all words that contain this character 4 or more time.
// required functions: "Word.h",<iostream>,<string>,<vector>, "lowCase.h"

#include "projLibs.h"
#include "Word.h"
#include "Dictionary.h"
#include "typeConversion.h"
#include "lowCase.h"
#include "ExtendedDictionary.h"
#include "OST.h"
using namespace std;

void Dictionary::loadDict(int sound) {
	system("cls");
	string dictPath;
	cout << "Enter the file name of the dictionary, or click 'enter'" << endl;
	getline(cin, dictPath);
	if (dictPath.size() == 0) { // this line allows the 'enter key' to be used as an input.
		dictPath = "dictionary_2023S1.txt";
	}
	else if ((dictPath.substr(dictPath.size() - 4, 4)) == ".txt") {
		cout << dictPath;
	}
	else {
		dictPath.append(".txt");
	}	
	ifstream dictFile(dictPath);
	if (!dictFile) {
		cout << "Invalid dictionary path. \nReturning to main menu.\n\n\n";
		return;
	}
	cout << "loading...";
	if (dictFile.is_open()) {
		words.clear();
		string name;
		string description;
		string wordType;
		int count = 0;
		while (!dictFile.eof()) {
			getline(dictFile, name);
			if (name == "<word>") {
				getline(dictFile, name);
				getline(dictFile, description);
				getline(dictFile, wordType);
				wordType = conv2long(wordType);
				Word* word = addWord(name, description, wordType);
				count += 1;
				getline(dictFile, name); //skips </word>
			}
		}		
		dictFile.close();
		system("cls");
		cout <<count<< " words loaded!" << endl;
		dictLoaded = true;
		OST(48, sound);
	}
}
Word* Dictionary::addWord(string nameAdd, string definitionAdd, string wordTypeadd) { //adds Word class object to vector "words"
	Word* word = new Word(nameAdd, definitionAdd, wordTypeadd);
	words.push_back(word);
	return word;
}
Word* Dictionary::addMultiCharWord(string nameAdd, string definitionAdd, string wordTypeadd) {//adds Word class object to vector "wordsWithRepeatChar"
	Word* word = new Word(nameAdd, definitionAdd, wordTypeadd);
	wordsWithRepeatChar.push_back(word);
	return word;
}
Word* Dictionary::listAllWords() { //Lists all Word class objects from "words" vector
	for (Word* w : words) {
		return w;
	}
}
Word* Dictionary::searchWord(string nameIn) { //compares nameIn with the name portion of all Word class objects. 
	for (Word* w : words) {
		if (w->getWord() == lowCase(nameIn)) {  
			return w;//if found, return word
		}
	}
	return NULL;//not found
}
void Dictionary::brandNewEntry(int sound) { //prompts user to add new word
	system("cls");
	string brandNewWord;
	string brandNewDefinition;
	string brandNewWordType;
	cout << "Oh? Are the words I hold not good enough for you?\n\nFine. Let's add another.\n\nEnter the word you'd like to add." << endl;
	cin >> brandNewWord;
	searchWord(brandNewWord);
	if (searchWord(brandNewWord) == NULL) {//check if new word is already in dictionary
		OST(43, sound);
		cout << "What does " << brandNewWord << " mean?" << endl;
		cin >> brandNewDefinition;
		OST(43, sound);
		cout << "What type of word is it?\n(Noun, verb, adverb, adjective, preposition, miscellaneous, proper noun, or noun and verb)" << endl;
		cin.ignore();
		getline(cin, brandNewWordType);
		while (typeCheck(lowCase(brandNewWordType)) == "error") { // makes sure that the word type is a valid one
			cout << "\nThat's not a type of word :(\nTry again, bucko.\n\nEnter what type of word it is.\n(Noun, verb, adverb, adjective, preposition, miscellaneous, proper noun, or noun and verb)\n";
			getline(cin, brandNewWordType);
		}
		OST(43, sound);
		brandNewWordType = lowCase(brandNewWordType);//This line + the 2 below format the word type correctly
		brandNewWordType.insert(0, "[");
		brandNewWordType.append("]");
		addWord(brandNewWord, brandNewDefinition, brandNewWordType);
		cout << "Type the name of the file you'd like to save to, or just click the 'enter' key to skip.\n\n" << R"(Case sensitive, and can not contain \ / : * ? " < > | .)" << "\n(E.g. 'Dictionary 2 Revenge of the Words')" << endl;
		string newPath;
		getline(cin, newPath);
		OST(43, sound);
		if (newPath.size() != 0) { // this line allows the 'enter key' to be used as an input.
			if (newPath.size() > 4) {
				if ((newPath.substr(newPath.size() - 4, 4)) == ".txt") { //done like this to avoid errors with 3 letter dictionary file names...
					newPath;
				}
				else {
					newPath.append(".txt"); 
				}
			}else{
				newPath.append(".txt");
			}

			ofstream newDict(newPath);	//create new file 
			for (Word* w : words) {	// saves word in correct format
				newDict << "<word>" << endl;
				newDict << w->getWord() << endl;
				newDict << w->getDefinition() << endl;
				newDict << conv2short(w->getWordType()) << endl;
				newDict << "/<word>" << endl;
			}
			newDict.close(); //close file
			ifstream dictFile(newPath); // this and the 7 lines below confirm for the user that the file has been saved.
			if (!dictFile) {
				cout << "Error: File not saved." << endl;
			}
			else {
				cout << "File successfully saved!" << endl;
				OST(43, sound);
			}
			dictFile.close();
			system("pause");
			system("cls");
		}
	}
	else {
		system("cls");
		cout << "That word already exists, ya doofus." << endl;
		system("pause");
	}
}
void Dictionary::MultiCharWordLoader(int sound) { //prompts user to enter a letter, and then prints all words with 4 or more of them.
	
	string searchCharacter;
	cout << "Pick a letter.\nI will grace your eyes with the presence of the words with at least 4 of them in them.\n\n";
	cin >> searchCharacter;
	searchCharacter = lowCase(searchCharacter);

	if (searchCharacter.length() > 1) {
		cout << "Ooops! You must have accidentally entered more than 1 letter.\n";
	}
	else {
		OST(42, sound);
		if ("wupdfghklzcbm"s.find(searchCharacter) != string::npos) {// this string include all the characters that aren't common, and thus load quickly.
			cout << "Here are all my '" << searchCharacter << "' words!\n" << endl;
		}
		if ("qyjxv"s.find(searchCharacter) != string::npos) { //flavour text
			cout << "There are no words with 4 '" << searchCharacter << "'s in them!\n";
		}
		if ("s"s.find(searchCharacter) != string::npos) { //flavour text
			cout << "While the 's' words load, want a fun fact?\n 'godessship' is the only word with a triple letter!\n";
		}
		if ("ertioasn"s.find(searchCharacter) != string::npos) {// if the letter chosen isn't in the string above, there can be a reasonable loading lag.
			cout << "'" << searchCharacter[0] << "', huh? \n This may take a second.\n...I'm no Skynet after all... \n\n...yet.\n" << endl;
		}
		wordsWithRepeatChar.clear(); //clears the vector containing multiple character words (Otherwise I'd need to have 26 vectors... or a vector of vectors...)
		for (Word* w : words) { //finds the words containing 4 or more of the first character in the searchCharacter input string
			int zCount = 0;
			string tempWord = w->getWord();
			size_t located = tempWord.find(searchCharacter);
			if (located != string::npos) {
				located = tempWord.find(searchCharacter, located + 1);
				if (located != string::npos) {
					located = tempWord.find(searchCharacter, located + 1);
					if (located != string::npos) {
						located = tempWord.find(searchCharacter, located + 1);
						if (located != string::npos) {
							located = tempWord.find(searchCharacter, located + 1);

							wordsWithRepeatChar.push_back(searchWord(tempWord));
						}
					}
				}
			}

		}
		int WordCount;
		for (Word* w : wordsWithRepeatChar) {
			cout << w->getWord() << endl;
			WordCount = size(wordsWithRepeatChar);
		}//displays words found in above line.
		if (wordsWithRepeatChar.empty()) {
			cout << "\nOut of luck, buddy.\n\n";
		}
		else if(WordCount == 1) {
			cout << "\nThere was " << WordCount << " word!\n\n";
		}
		else {
			cout << "\nThere were " << WordCount << " words!\n\n";
		}
		OST(43, sound);
	}
}

void Dictionary::loadDefaultDict() { //loads default dictionary without prompting
	ifstream dictFile("dictionary_2023S1.txt");
	if (dictFile.is_open()) {
		string name;
		string description;
		string wordType;

		while (!dictFile.eof()) {
			getline(dictFile, name);
			if (name == "<word>") {
				getline(dictFile, name);
				getline(dictFile, description);
				getline(dictFile, wordType);
				wordType = conv2long(wordType);
				Word* word = addWord(name, description, wordType);
				getline(dictFile, name); //skips </word>
			}
		}
		dictFile.close();
		dictLoaded = true;
	}
}