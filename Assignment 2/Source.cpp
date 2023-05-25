// Source.cpp file
// Main file from which all other files are run from.
// 
// Monte Shub - 10/04/2023
// 
// For the menu interface, the following functions were required: <iostream>, <string>, <stdlib.h>, <windows.h>, <chrono>, <thread>, <conio.h> <sstream>, "Dictionary.h", "Word.h", "typeConversion.h", "lowCase.h", "ExtendedDictionary.h", "title.h", "wordColour.h"
//
// Function: ShowConsoleCursor(bool showFlag)
// input: bool showFlag
// output: None
// description: if showFlag is true, the cursor will be displayed. If false; the cursor will be hidden. 
// functions required: <iostream>,<string>, <windows.h>
//
// Function: displayWord(Word* searchedWord)
// input: an  object of the Word class
// output: string name (from the associated Word class object)
// description: When given a Word class object; the name part of the object is returned.
// functions required: <iostream>,<string>
//
// Function: displayDefinition(Word* searchedWord)
// input: an  object of the Word class
// output: string definition (from the associated Word class object)
// description: When given a Word class object; the definition part of the object is returned.
// functions required: <iostream>,<string>
//
// Function: displayWordType(Word* searchedWord)
// input: an  object of the Word class
// output: string word type (from the associated Word class object)
// description: When given a Word class object; the word type part of the object is returned.
// functions required: <iostream>,<string>
//
// Function: displayWordLength(Word* searchedWord)
// input: an  object of the Word class
// output: int representing the number of letters in the name part (from the associated Word class object)
// description: When given a Word class object; the length of the name part of the object is returned.
// functions required: <iostream>,<string>

#include "projLibs.h"
#include <sstream>
#include "Dictionary.h"
#include "Word.h"
#include "typeConversion.h"
#include "lowCase.h"
#include "ExtendedDictionary.h"
#include "title.h"
#include "wordColour.h"
#include <mmsystem.h>
#include "OST.h"
using namespace std;

void ShowConsoleCursor(bool showFlag) // hides the cursor. Purely visual.
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
string displayWord(Word* searchedWord) {// returns "word"(/name) part of an entry in the dictionary
	if (searchedWord != NULL) {
		return searchedWord->getWord();
	}
	return "That isn't a word..."; 
}
string displayDefinition(Word* searchedWord) {// returns definition part of an entry in the dictionary
	if (searchedWord != NULL) {
		return searchedWord->getDefinition();
	}
	return "That isn't a word...";
}
string displayWordType(Word* searchedWord) {// returns word-type of an entry in the dictionary
	if (searchedWord != NULL) {
		return searchedWord->getWordType();
	}
	return "That isn't a type of word...";
}
int displayWordLength(Word* searchedWord) {// returns length of the "word"(/name) part of an entry in the dictionary
	if (searchedWord != NULL) {
		return searchedWord->getLetterCount();
	}
	return 0;
}
ExtendedDictionary simplefunc(ExtendedDictionary dictionary)
{
	dictionary.loadDefaultDict();
	return dictionary;
}

int main() {
	string soundLogo[14] = { R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)",R"(RRRRRRRRRN@@@@RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR)",R"(         ]@@@@       ,,,,                ,,,,    ,,,,,,             ,,,,,,      )",R"(         ]@@@@       @@@@P              ]@@@@     "%@@@@N         ,@@@@@P-      )",R"(         ]@@@@       @@@@P              ]@@@@        %@@@@@,    g@@@@@P         )",R"(         ]@@@@       @@@@P              ]@@@@          *@@@@@,g@@@@@*           )",R"(         ]@@@@       @@@@@gggggggggggggg@@@@@            "B@@@@@@@"             )",R"(         ]@@@@       @@@@@@@@@@@@@@@@@@@@@@@@            g@@@@@@@@W             )",R"(         ]@@@@       @@@@P              ]@@@@         ,g@@@@@*'%@@@@@,          )",R"(         ]@@@@       @@@@P              ]@@@@       ,@@@@@N"     %@@@@@,        )",R"(         ]@@@@       @@@@P              ]@@@@     ,@@@@@P          *B@@@@g      )",R"(         -MMMM       MMMM~              -MMMM   -MMMMM*              "MMMMM~    )",R"(,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,)",R"(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@)" };
	srand(time(NULL)); //seed random function
	ShowConsoleCursor(false);
	ExtendedDictionary dictionary; //dict class -> dict object
	dictionary.loadSettings();//load settings.txt file
	bool sound = false;

	if (dictionary.Audio != 0) {
		sound = true;
		OST(35, 1);
		for (int i = 0; i < 14; i++) {
			printf("\033[%d;%dH", 2 + i, 20);
			std::cout << soundLogo[i];
		}
		wordColour(18, 50, 3, 4, "(Audio is Enabled.)");
		printf("\033[%d;%dH", 10, 58);
		this_thread::sleep_for(chrono::milliseconds(3500));
		}
	
	if (dictionary.playTitle) {// playTitle is a toggle setting
		system("cls");

		this_thread::sleep_for(chrono::milliseconds(250));
		thread A(title,sound);	//MULTITHREADING! While the title is playing...
		thread B(&ExtendedDictionary::loadDefaultDict, &dictionary);// ... the default dictionary is loaded.

		A.join();
		B.join();
	}
	if (dictionary.loadDefault && !(dictionary.dictLoaded) && !(dictionary.playTitle)) { //If the setting to autoload dictionary is enabled, the default dictionary is loaded.
		cout << "\n[Autoload Enabled]\n\nLoading Dictionary...";
		dictionary.loadDefaultDict();
	}
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //this and the line above allow for fully sick colouring
	int textRow = 8;	//"baseline" height for the text
	int textIndent = 1; //as above for indentantion.
	string options[9] = { "Load Dictionary.", //menu options
						  "Word Search.",
						  "Multiple Character Checker.",
						  "Add a Word",
						  "Palindrome Finder",
						  "Rhyming Dictionary",
						  "Word Guessing Game!",
						  "Cheat at Wordle",
	                      "Option(s)"};
	string optionsMenuOptions[5] = {"Toggle Default Dictionary: ","Clear High Score","Skip Cinematic Brilliance","Toggle Audio","Return to main"}; // Options menu options
	//line below is a string of ascii for the "dictionary" heading
	string mainTitle[6] = {R"(    ____  _      __  _                             )",R"(   / __ \(_)____/ /_(_)___  ____  ____ ________  __)",R"(  / / / / / ___/ __/ / __ \/ __ \/ __ `/ ___/ / / /)",R"( / /_/ / / /__/ /_/ / /_/ / / / / /_/ / /  / /_/ / )",R"(/_____/_/\___/\__/_/\____/_/ /_/\__,_/_/   \__, / )", R"(                                          /____/ )"};

	bool optionsOpen = false; //bool flag to swap main menu with options menu
	int optionsSelect = 0; //options cursor position


	int selection = 0; // menu cursor poistion
	OST(2, dictionary.Audio);

	while (true) {
		system("cls");

		if (!optionsOpen) {
			SetConsoleTextAttribute(hConsole, 7);//colours text. 7 = white
			for (int k = 0; k < sizeof(mainTitle) / sizeof(mainTitle[0]); k++) {//prints ASCII text "Dictionary"
				printf("\033[%d;%dH", 1 + k, 1);
				std::cout << mainTitle[k];
			}
			wordColour(3, textIndent + 60, 3, 6, "Navigate with [Up]");
			wordColour(3, textIndent + 79, 2, 6, "and [Down] Arrows.");
			wordColour(4, textIndent + 60, 3, 10, "Confirm with [Enter] Key.");
			wordColour(5, textIndent + 60, 4, 4, "Quit with the [Escape] Key.");

			SetConsoleTextAttribute(hConsole, 7);
			for (int i = 0; i < (sizeof(options) / sizeof(options[0])); i++) { //prints main menu 'options'
				printf("\033[%d;%dH", i + textRow, textIndent);
				std::cout << options[i];
			}
		
			SetConsoleTextAttribute(hConsole, 112);// highlights the cursor. 112 = black on white
			printf("\033[%d;%dH", selection + textRow, textIndent);
			std::cout << options[selection];
		}
		if (optionsOpen) { //OPTIONS MENU
			SetConsoleTextAttribute(hConsole, 7);
			printf("\033[%d;%dH", 1, 1);
			std::cout << "Options!";
			for (int i = 0; i < (sizeof(optionsMenuOptions) / sizeof(optionsMenuOptions[0])); i++) {//handles the printing of options menu options
				printf("\033[%d;%dH", i + textRow, textIndent);
				std::cout << optionsMenuOptions[i];
			}
			SetConsoleTextAttribute(hConsole, 112);// highlights the cursor
			printf("\033[%d;%dH", selection + textRow, textIndent);
			std::cout << optionsMenuOptions[optionsSelect];

			if (dictionary.loadDefault) {

				SetConsoleTextAttribute(hConsole, 2);// colours text. 2 = green
				printf("\033[%d;%dH", 8, 30);
				std::cout << "[Autoload Enabled]";
			}
			else {
				SetConsoleTextAttribute(hConsole, 12); // colours text. 12 = red
				printf("\033[%d;%dH", 8, 30);
				std::cout << "[Autoload Disabled]";
			}
			if (dictionary.playTitle) {
				SetConsoleTextAttribute(hConsole, 2); //colours text green
				printf("\033[%d;%dH", 10, 30);
				std::cout << "[Title Sequence Enabled]";
			}
			else {
				SetConsoleTextAttribute(hConsole, 12); //colours text red
				printf("\033[%d;%dH", 10, 30);
				std::cout << "[Title Sequence Disabled]";
			}
			if (dictionary.Audio == 2) {
				SetConsoleTextAttribute(hConsole, 2); //colours text green
				printf("\033[%d;%dH", 11, 30);
				std::cout << "[Music Enabled]";
			}
			if (dictionary.Audio == 1) {
				SetConsoleTextAttribute(hConsole, 1); //colours text blue
				printf("\033[%d;%dH", 11, 30);
				std::cout << "[SFX Enabled]";
			}
			if (dictionary.Audio == 0) {
				SetConsoleTextAttribute(hConsole, 12); //colours text red
				printf("\033[%d;%dH", 11, 30);
				std::cout << "[Audio Disabled]";
			}
		}																						
		if (dictionary.dictLoaded && !optionsOpen) { //if dictionary is loaded and options are closed
			SetConsoleTextAttribute(hConsole, 2);//colours text green
			printf("\033[%d;%dH", 8, 20);
			std::cout << "[Dictionary loaded]";//prints on main menu
		}
		if (dictionary.playTitle && !optionsOpen) {
			SetConsoleTextAttribute(hConsole, 14);//colours text green
			printf("\033[%d;%dH", 8, textIndent + 60);
			std::cout << "Note: Title cinematic can be disabled in options.";//prints on main menu
		}
		if (dictionary.loadDefault && !optionsOpen) {
			SetConsoleTextAttribute(hConsole, 2);
			printf("\033[%d;%dH", textRow+ (sizeof(options) / sizeof(options[0])) -1, 20);
			std::cout << "[Default Dictionary Autoload: Enabled]";
		}
		SetConsoleTextAttribute(hConsole, 7);
		switch (_getch()) { // gets input from key presses for menu
		case KEY_ESCAPE: //click escape to quit
			if (!optionsOpen) {

				dictionary.saveSettings();//Save settings to settings.txt
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				OST(46, dictionary.Audio);
				cout << "goodbye, QUITTER.";
				this_thread::sleep_for(chrono::milliseconds(1800));
				return 0;
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				optionsOpen = false;
			}
		case KEY_UP:
			if (!selection < 1 ) {// moves cursor up
				selection -= 1;
			}
			if (!optionsSelect < 1) { //moves options cursor up.
				optionsSelect -= 1;
			}

			break;
		case KEY_DOWN:
			int MaxScroll;
			if (!optionsOpen) {
				MaxScroll = (sizeof(options) / sizeof(options[0])) - 1;
			}
			else {
				MaxScroll = (sizeof(optionsMenuOptions) / sizeof(optionsMenuOptions[0])) - 1;
			}
			if (selection < MaxScroll) { //moves cursor down
				selection += 1;
			}
			if (optionsSelect < MaxScroll) { //moves cursor down
				optionsSelect += 1;
			}
			if (optionsSelect > MaxScroll) {// defaults the cursor to the start of the options menu
				optionsSelect = 0;
			}
			break;


			//
			// MENU OPTIONS BELOW *****************************************************
			// 
			


		case KEY_ENTER: //bunch o' ifs. essentially just does a thing corresponding to the selection number (and thus menu)
			switch (selection) {


			case 0: {
				SetConsoleTextAttribute(hConsole, 7);
				if (!optionsOpen) {
					OST(26, dictionary.Audio);
					dictionary.loadDict(dictionary.Audio); //loads dictionary
					system("pause");
				}
				else {
					if (dictionary.loadDefault) {
						OST(45, dictionary.Audio);
					}
					if (!dictionary.loadDefault) {
						OST(44, dictionary.Audio);
					}
					dictionary.setDefault(); // toggles the autoload dictionary setting
				}
				system("cls");
				break;
			}


			case 1: { //word search
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				string nameSearch;
				string individualWord;
				if (!optionsOpen) {
					OST(27, dictionary.Audio);
					if (!dictionary.dictLoaded) {//dictionary not loaded message
						cout << "I'm all for pointless tasks \n\n*gestures to 90% of this program* \n\nbut I'll need you to load a dictionary file first...\n\n";
						system("pause");
					}
					else {
						cout << "Enter a word for me to define for you.\n";
						getline(cin, nameSearch);
						OST(49, dictionary.Audio);
						//cin >> nameSearch;
						system("cls");
						if (nameSearch.find(" ") != string::npos) {
							stringstream ss;
							ss << nameSearch;
							cout << "You seem to have entered a few words...\nI know you must be really keen to learn, but you have to go one at a time.\n\nIn case you forgot, you entered:\n";
							while (!ss.eof()) {
								ss >> individualWord;
								cout <<"--"<< individualWord << endl;
							}
						}
						else {
							cout << displayWord(dictionary.searchWord(nameSearch)) << endl;// prints word
							if (displayWord(dictionary.searchWord(nameSearch)) != "That isn't a word...") {
								cout << displayWordType(dictionary.searchWord(nameSearch)) << endl;//prints definition
								cout << displayDefinition(dictionary.searchWord(nameSearch)) << "\n\n\n\n\n";//prints word type
								OST(43, dictionary.Audio);
							}
							else {
								OST(10, dictionary.Audio);
							}
						}
						system("pause");
						cin.clear();
					}
				}
				else {
					OST(38, dictionary.Audio);
					dictionary.highScore = 0; // if in the options menu, it resets your high score :( 
				}
				system("cls");
				break;
			}


			case 2: { //multi char words
				SetConsoleTextAttribute(hConsole, 7);
				string searchCharacter;
				system("cls");
				if (!optionsOpen) {
					OST(28, dictionary.Audio);
					if (!dictionary.dictLoaded) { //dumb message that prints if you click this setting without the dictionary loaded
						cout << "Unfortunately, these are all the words I have access to at the moment:\n\n\n\n\n\n(Load a dictionary.)\n\n\n\n";
						system("pause");
						system("cls");
					}
					else {
						dictionary.MultiCharWordLoader(dictionary.Audio);
						system("pause");
					}
				}
				else{
					if (dictionary.playTitle && (selection == 2)) {
						OST(37, dictionary.Audio);
					}
					else if (!dictionary.playTitle && (selection == 2)) {
						OST(36, dictionary.Audio);
					}
					dictionary.setTitle(); // enable/disable the title 'cinematic' to be played.
				}
				system("cls");
				break;
			}


			case 3: { // new word
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				if (!optionsOpen) {
					OST(29, dictionary.Audio);
					if (!dictionary.dictLoaded) {//another dumb message for if dictionary isn't loaded
						cout << "I probably could let you define a new word to put in a blank dictionary, but it feels like a bit of a cop-out.\n\nTry loading a dictionary file first, and then we'll try again.\n\n";
						system("pause");
					}
					else {
						ShowConsoleCursor(true);//enables the standard line cursor (easier when typing)
						dictionary.brandNewEntry(dictionary.Audio); //add an entry, then optionally save dictionary as new file.
						ShowConsoleCursor(false);//disables standard line cursor
					}
				}
				else {
					if (dictionary.Audio == 2) {
						OST(39, 1);
					}
					if (dictionary.Audio == 0) {
						OST(40, 1);
					}
					if (dictionary.Audio == 1) {
						OST(41, 1);
					}
					dictionary.AudioToggle(); // closes the options, and saves the settings
				}
				system("cls");
				break;
				OST(2, dictionary.Audio);
			}


			case 4: {// palindrome search
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				if (!optionsOpen) {
						OST(30, dictionary.Audio);
					if (!dictionary.dictLoaded) {//dumb/ insulting message for if dictionary isn't loaded
						cout << "Without a dictionary loaded, I can't search for palindromes.\n\nI can guess though!\n\nIs 'smooth-brained' a palindrome?\n\n\n";
					}
					else {
						cout << "List of palindromes:\n";
						dictionary.showPalindrome();
						cout << "\nDid you know that longest palindrome in everyday use is the Finnish word for a soapstone vendor:'saippuakivikauppias'?\nI don't know much about Finnish culture, but I'm guessing it's just one of those big words you whip out when you want to sound impressive, like ferroequinologist. (train enthusiast)\n";
					}
					system("pause");
				}
				else {
					dictionary.saveSettings(); // closes the options, and saves the settings
					optionsOpen = false;
					OST(47, dictionary.Audio);
					OST(2, dictionary.Audio);
				}
				system("cls");
				break;
			}


			case 5: { //rhyming
				SetConsoleTextAttribute(hConsole, 7);
				string rhymeBase;
				system("cls");
					OST(31, dictionary.Audio);
				if (!dictionary.dictLoaded) {//no-dictionary message
					cout << "trying to rhyme without any words...\n\nThat's... so poetic...\n\n\n\nAlso it's impossible. Load a dictionary file first.\n\n\n";
				}
				else {
					cout << "Roses are red,\nviolets are blue,\nmost poems rhyme,\nbut this one doesn't.\n\n\nEnter a word, and I'll give you some words that (kind of) rhyme!\n";
					cin >> rhymeBase; //base word in which to search for "rhymes"
					system("cls");
					dictionary.findRhymes(rhymeBase);
				}
				system("pause");
				system("cls");
				break;
			}


			case 6: { //guessing game
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
					OST(32, dictionary.Audio);
				if (!dictionary.dictLoaded) {
					cout << "Guess the word!\n\nLoad a _______ dictionary file!\n\n";
					system("pause");
					system("cls");
				}
				else {
						OST(1, dictionary.Audio); //music start
					dictionary.guessingGame(); // launch guessing game
					OST(0, dictionary.Audio); // music stop
					OST(2, dictionary.Audio);
				}				
				system("cls");
				break;
			}


			case 7: { //cheatle
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				OST(33, dictionary.Audio);
				if (!dictionary.dictLoaded) {//dumb/insulting no dictionary message
					cout << "I probably can't help you pretend to be smarter than you are if I have no words in me. \n\nLoad a dictionary file.\n\n";
				}
				else {
					OST(2,dictionary.Audio);
					OST(3, dictionary.Audio);
					dictionary.cheatle(); //launch the wordle cheating function thing
					OST(0, dictionary.Audio);
					OST(2, dictionary.Audio);
				}
				system("cls");
				break;
			}


			case 8: { //open options menu
				SetConsoleTextAttribute(hConsole, 7);
				system("cls");
				OST(34, dictionary.Audio);				
				optionsSelect = 0;
				selection = 0;
				optionsOpen = true; // options menu flag
				system("cls");				
				OST(2, dictionary.Audio);
				break;
			}
			}
			break;
		}
	}
}
