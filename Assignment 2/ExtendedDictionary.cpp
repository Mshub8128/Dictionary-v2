// ExtendedDictionary.cpp file
// This contains the implementation of the ExtendedDictionary class.
// 
// Monte Shub - 17/03/2023
//
// Function: showPalindrome();
// inputs: None	
// outputs: None
// description: calls Palindrome() function from Word class, adds it to PalindromeWords vector, then prints all palinedromes. 
// required functions: <iostream>,<string>,<vector>,"word.h",<stdlib.h>
// 
// Function: findRhymes(string)
// input: Word that user wishes to find rhymes for (string)
// output: None
// description: Finds all words in words vector that shares the last 3 letters with input word. Returns error message if word is less than 4 characters.
// required functions: <iostream>,<string>,<vector>,"word.h"  
// 
// Function: guessingGame()
// input: None
// output: None
// description: Initialises the guessing game function. The user is presented a random word, and then must input what they think they 4th word in the description entry is. Correctly guessing the word adds 10 points to your highscore. *additional specific functionality
// required functions: <iostream>,<string>,<vector>,"word.h",<windows.h>
// 
// Function: definitionBlanker()
// input: None
// output: word that has been blanked from description for guessing game. (string)
// description: Returns the word to be guessed for guessing game, as well as printing the word and description with blanked 4th word.
// required functions: <iostream>,<string>,<vector>,"word.h",<sstream> 
// 
// Function: loadDefaultDict()
// input: None
// output: None
// description: Loads the default dictionary file.
// required functions: <iostream>,<string>,<vector>,"word.h",<fstream>
// 
// Function: setDefault()
// input: None
// output: None
// description: Toggles autoloading the default dictionary file.
// required functions: <iostream> 
// 
// Function: setTitle()
// input: None
// output: None
// description: toggles playing the intro cinematic
// required functions: <iostream> 
//
// Function: loadSettings()
// input: None
// output: None
// description: Loads from settings file (settings.txt)
// required functions: <iostream>,<string>,<fstream>  
// 
// Function: saveSettings()
// input: None
// output: None
// description: Saves settings to settings file (settings.txt)
// required functions: <iostream>,<string>,<fstream> 
// 
// Function: cheatle()
// input: None
// output: None
// description: Initialises the cheatle (cheating at wordle) function. The user is prompted to select word length, which letters are excluded, included, and included in specific location for a word. All words that fit these set of requirements are then returned to the user, and the process can be repeated.
// required functions: <iostream>,<string>,<fstream>,<vector>,"word.h",<stdlib.h>,<windows.h>,<chrono>,<thread>,<conio.h>  
 

#include "projLibs.h"
#include "Word.h"
#include "ExtendedDictionary.h"
#include "typeConversion.h"
#include "lowCase.h"
#include <sstream>
#include "wordColour.h"
#include "OST.h"

using namespace std;

//below are all the values needed for keyboard inputs for 'getch'
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESC 27
#define KEY_ZERO 48
#define KEY_ONE 49
#define KEY_TWO 50
#define KEY_THREE 51
#define KEY_FOUR 52
#define KEY_FIVE 53
#define KEY_SIX 54
#define KEY_SEVEN 55
#define KEY_EIGHT 56
#define KEY_NINE 57
int Audio;
void ExtendedDictionary::showPalindrome() {//the getter for the palindrome vector
	if(PalindromeWords.empty()){ // if palindrome vector is empty, it finds the palindromes and loads them into the vector
		int count = 0;
		int column = 0;
		for (Word* w : words) {
			if (w->Palindrome()) {
				PalindromeWords.push_back(w);
				if (count >= 20) {
					column += 1;
					count = 0;
				}
				printf("\033[%d;%dH", 4+count, 1+20*column);
				std::cout << w->getWord() << endl;
				count += 1;
				printf("\033[%d;%dH", 25, 1);
			}
		}
	}
	else {// palindromes already loaded
		int count = 0;
		int column = 0;
		for (Word* w : PalindromeWords) {
			if (count >= 20) {
				column += 1;
				count = 0;
			}
			printf("\033[%d;%dH", 4 + count, 1 + 20 * column);
			std::cout << w->getWord() << endl;
			count += 1;
			printf("\033[%d;%dH", 25, 1);
		}
	}
}
void ExtendedDictionary::findRhymes(string baseWord) { //finds all words that share the last 3 letters as the input	
	int wordCount = 0;
	if (baseWord.length() < 3) {
		cout << "I think this word might be too short to rhyme...\n";
	}
	else if (baseWord.length() >= 4) {
		for (Word* w : words) {			//loads all words 4 letters or longer
			if (w->getWord().length() >= 4) {
				if ((w->getWord()).substr((w->getWord()).length() - 3, 3) == baseWord.substr(baseWord.length() - 3, 3)) {// compares the last 3 letters of all words (with 4 or more letters) with the user input
					cout << w->getWord() << endl;//shows the words that share the last 3 letters
					wordCount += 1;
				}
			}
		}
	}
	cout << "There are " << wordCount << " words that rhyme with " << baseWord<< "!\n";
}
void ExtendedDictionary::guessingGame() { // initiates the guessing game
	HANDLE  hConsole; 
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // this line and previous had to be reinitialised to display colours
	system("cls");
	int colours[12] = { 4,12,6,2,9,5,13,5,9,2,6,12 }; //set of colours that I thought looked good
	string title[14] = { "G", "u", "e", "s", "s", "i", "n", "g"," ", "G", "a", "m", "e", "!" };// I had to split the string into a list of chars for an effect that'll be obvious below
	int n = 0; //various counters for colour/ positioning
	int m = 0;
	int t = 0;
	bool gameTime = true; //bool flag for the game running
	int menuSelection = 0;//menu cursor position
	int quitSelection = 0;//quit menu cusor position
	bool firstGame = true;// bool flag to register if it's the first game or not
	int clearSelection = 1; // int required for clearing the cursor 
	bool quit = false; //check before quiting flag
	string cursor[31] = { "-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","|"};

	string winningStreak[8] = { "wow","many smarts","wow","many words","amazing","such verbose","wow","very wow"};
	string playAgainMenu[2] = { "I want to keep going!","It's Time to say goodbye." };
	string gameMenu[2] =      { "Heck yeah, I'm Ready!","On second thoughts, no..." };
	string quitMenu[2] =      { "No. I  must continue!","Yes, I'm a big ol' baby.." };
	
	int randomRow[sizeof(winningStreak)];//coordinates for winning streak effect
	int randomCol[sizeof(winningStreak)];//randomizes in 4 lots, so that it avoids printing over non-empty space
	for (int j = 0; j < 2; j++) {
		randomRow[j] = rand() % 3 + 6;
		randomCol[j] = rand() % 110;
	}
	for (int j = 2; j < 4; j++) {
		randomRow[j] = rand() % 9 + 18;
		randomCol[j] = rand() % 110;
	}
	for (int j = 4; j < 6; j++) {
		randomRow[j] = rand() % 26 + 6;
		randomCol[j] = rand() % 25;
	}
	for (int j = 6; j < 8; j++) {
		randomRow[j] = rand() % 26 + 6;
		randomCol[j] = rand() % 42 + 68;
	}
	bool HighScoreSound = false;
	while (gameTime) { // game start
		
		for (int i = 0; i < 30; i++) {

			n += 1;
			m += 1;
			t += 1;
			if (n == 12) {
				n = 0;
			}
			if (t == 14) {
				t = 0;
			}
			if (m == 4) {
				m = 0;
			}
			
			SetConsoleTextAttribute(hConsole, colours[n]); //title
			printf("\033[%d;%dH", 1, t + 10);
			cout << title[t];

			SetConsoleTextAttribute(hConsole, colours[n]);// highlights the cursor
			printf("\033[%d;%dH", 13 + menuSelection * 3, 38 + i);
			std::cout << cursor[i];	
			SetConsoleTextAttribute(hConsole, colours[n]);// highlights the cursor
			printf("\033[%d;%dH", 14 + menuSelection * 3, 38);
			std::cout << cursor[30];
			printf("\033[%d;%dH", 14 + menuSelection * 3, 67);
			std::cout << cursor[30];
			SetConsoleTextAttribute(hConsole, colours[n]);// highlights the cursor
			printf("\033[%d;%dH", 15 + menuSelection * 3, 67 - i);
			std::cout << cursor[29-i];

			SetConsoleTextAttribute(hConsole, 4);// clears the cursor
			printf("\033[%d;%dH", 13 + clearSelection * 3, 38);
			std::cout << "                              ";
			printf("\033[%d;%dH", 14 + clearSelection * 3, 38);
			std::cout << " ";
			printf("\033[%d;%dH", 14 + clearSelection * 3, 67);
			std::cout << " ";
			printf("\033[%d;%dH", 15 + clearSelection * 3, 38);
			std::cout << "                              ";
			
			if (!firstGame) {
				if ((yourScore >= highScore) && gameloses ==0) {// if you beat the high score it gives you an occular prize
					highScore = yourScore;
					//HighScoreSound = true;
					
					for (int j = 0; j < (sizeof(winningStreak) / sizeof(winningStreak[0])); j++) {
						SetConsoleTextAttribute(hConsole, colours[n]);// colours the 'prize'
						printf("\033[%d;%dH", randomRow[j], randomCol[j]);
						std::cout << winningStreak[j];						
					}					
				}
			}
			if (!quit) {
				if (firstGame) {//prints rules/high score/ losing streak and presents the first menu
					this_thread::sleep_for(0.02s);//required pause for visual effect
					SetConsoleTextAttribute(hConsole, 15);
					printf("\033[%d;%dH", 3, 1);
					std::cout << "Rules:\nI pick a random word.\nYou get the word and (most of) the definition.\nYou have to guess the missing word.\n";

					for (int j = 0; j < 2; j++) {
						printf("\033[%d;%dH", 14 + j * 3, 40);
						std::cout << gameMenu[j]; //prints game menu
					}
				}
				else { //if not your first game
					this_thread::sleep_for(0.02s);
					SetConsoleTextAttribute(hConsole, 15);
					printf("\033[%d;%dH", 10, 40);
					std::cout << "Want to play again?";//prints play again message
				
					for (int j = 0; j < 2; j++) {
						printf("\033[%d;%dH", 14 + j * 3, 40);
						std::cout << playAgainMenu[j]; // and play again menu
					}
				}
			}
			else {
				for (int j = 0; j < 2; j++) {
					SetConsoleTextAttribute(hConsole, 15);
					printf("\033[%d;%dH", 14 + j * 3, 40);
					std::cout << quitMenu[j];//loads quit menu
				}
			}
			printf("\033[%d;%dH", 1, 70);
			std::cout << "High Score: " << highScore;//prints high score
			printf("\033[%d;%dH", 2, 70);
			std::cout << "Your Score: "<< yourScore;//prints high score

			if (gameloses >= 10) {// prints consecutive loses
				printf("\033[%d;%dH", 3, 70);
				std::cout << "Consecutive loses: " << gameloses << "    LOLOLOLOLOLOLOLOL";
			}
			if (gameloses < 10) {
				printf("\033[%d;%dH", 3, 70);
				std::cout << "Consecutive loses: " << gameloses;
			}
			
			if(_kbhit()){// this allows the loop to continue without a key press. otherwise the menu colour is static
				switch ((_getch())) { // gets input from key presses for menu
				case KEY_ESCAPE: //click escape to quit
					SetConsoleTextAttribute(hConsole, 7);
					system("cls");
					quit = true;
					printf("\033[%d;%dH", 10, 40);
					std::cout << "Are you giving up like a baby?";

					break;
				case KEY_UP:
					if (menuSelection != 0) {// moves cursors up
						menuSelection -= 1;
						quitSelection -= 1;
						clearSelection += 1;					
					}
					break;
				case KEY_DOWN:
					if (menuSelection != 1) { //moves cursors down
						menuSelection += 1;
						quitSelection += 1;
						clearSelection -= 1;					
					}
					break;
				case KEY_ENTER:
					if (!quit && menuSelection == 0) {//READY
						string answer;
						string guess;

						system("cls");
							OST(6,Audio);

						answer = definitionBlanker(); // calls a function that grabs a random word/ definition and blanks the 4th word
						if (answer.substr(answer.size() - 1, 1) == ";") {// if the 4th word includes a ';' in it, prevents it being required in the answer
							answer = answer.substr(0, answer.size() - 1);
						}		
						std::cout << endl<<endl;
						cin >> guess;
						OST(0, Audio);
						if (answer == guess || answer == lowCase(guess)) {
							std::cout << "\nNice!\n";
							
							yourScore += 10;
							if (Audio==1) {
								OST(8, Audio);
								if (yourScore == highScore) {
									HighScoreSound = true;
								}
							}
							gameloses = 0;
							firstGame = false;

						}
						if (answer != guess) {
							std::cout << "\nNope :(\n\nThe correct answer was: "<<answer<<"\n\n";
								OST(10, Audio);
							
							firstGame = false;
							bool HighScoreSound = false;
							gameloses += 1;
						}
						system("pause");

						for (int j = 0; j < 2; j++) {		//re-randomize the 'prize'
							randomRow[j] = rand() % 3 + 6;
							randomCol[j] = rand() % 110;
						}
						for (int j = 2; j < 4; j++) {
							randomRow[j] = rand() % 9 + 18;
							randomCol[j] = rand() % 110;
						}
						for (int j = 4; j < 6; j++) {
							randomRow[j] = rand() % 26 + 6;
							randomCol[j] = rand() % 25;
						}
						for (int j = 6; j < 8; j++) {
							randomRow[j] = rand() % 26 + 6;
							randomCol[j] = rand() % 42 + 68;
						}
						system("cls");
						if (HighScoreSound && gameloses == 0) {
							OST(7, Audio);
						}
					}

					if (!quit && menuSelection == 1) {//QUIT BEFORE STARTING
						gameTime = false;
						system("cls");

					}
					if (quit && quitSelection == 0) {//CANCEL IN GAME QUIT
						quit = false;
						saveSettings();
						system("cls");

					}
					if (quit && quitSelection == 1) {//CONFIRM QUIT
						gameTime = false;
						system("cls");
					}
				}
			}
		}
	}
}
string ExtendedDictionary::definitionBlanker() { //blanks out the 4th word in a randomly selected word
	string tempWord;
	string defWord;
	string randomWord;
	string randomDefinition;
	string guessWord;
	bool sizeCheck = true;
	while (sizeCheck) {
		int count = 0;
		int randomWordNum = rand() / float(RAND_MAX) * words.size(); //CHECK THIS RAND
		randomDefinition = words[randomWordNum]->getDefinition();
		stringstream bd;//bd (blanked definition) 
		bd << randomDefinition;
		randomDefinition = "";
		while (!bd.eof()) {
			count += 1; //first word is 1, not 0 like indexes
			bd >> tempWord;
			if (count == 4) {
				randomDefinition += alphaOnly(tempWord) + " "; 
				guessWord = tempWord;
			}
			if (count != 4) { //WHY NOT ELSE
				randomDefinition += tempWord + " ";
			}
		}
		if (count > 4) {
			sizeCheck = false;
		}
		randomWord = words[randomWordNum]->getWord();
	}
	cout << "Let's go!\n\nOk Chump, fill in the blank!\n\n      Word: "<<randomWord<<"\n\nDefinition: "<< randomDefinition;

	return guessWord;
}
void ExtendedDictionary::setDefault() { //toggle autoloading of default dictionary
	if (loadDefault) {
		loadDefault = false;
	}
	else {
		loadDefault = true;
	}
}
void ExtendedDictionary::setTitle() { //toggles playing the title
	if (playTitle) {
		playTitle = false;
	}
	else {
		playTitle = true;
	}
}
void ExtendedDictionary::loadSettings() { // load settings saved to settings.txt
	bool Loaded = false;
	ifstream settingsFile("settings.txt");
	
	while (!Loaded) {
		if (settingsFile.is_open()) {
			int score;
			string line;
			string tempLine;
			while (!settingsFile.eof()) {
				getline(settingsFile, line);
				if (line == "<START>") {
					getline(settingsFile, line);
				}
				if (line == "<highScore>") {
					(getline(settingsFile, line));
					ExtendedDictionary::highScore = stoi(line);
					(getline(settingsFile, line));
				}
				if (line == "<loadDefault>") {
					(getline(settingsFile, line));
					if (line == "1") {
						ExtendedDictionary::loadDefault = true;
					}
					(getline(settingsFile, line));
				}
				if (line == "<playTitle>") {
					(getline(settingsFile, line));
					if (line == "1") {
						ExtendedDictionary::playTitle = true;
					}
					(getline(settingsFile, line));
				}
				if (line == "<Audio>") {
					(getline(settingsFile, line));
					if (line == "0") {
						ExtendedDictionary::Audio = 0;
					}
					if (line == "1") {
						ExtendedDictionary::Audio = 1;
					}
					if (line == "2") {
						ExtendedDictionary::Audio = 2;
					}
					(getline(settingsFile, line));
				}
				settingsFile.close();			
			}
			Loaded = true;
		}
		break;
	}
} 
void ExtendedDictionary::saveSettings() { //saves settings to settings.txt
	ofstream settingsFile("settings.txt");	//create new file if one isn't there
	settingsFile << "<START>" << endl;
	settingsFile << "<highScore>" << endl;
	settingsFile << highScore << endl;
	settingsFile << "<loadDefault>" << endl;
	settingsFile << loadDefault << endl;
	settingsFile << "<playTitle>" << endl;
	settingsFile << playTitle << endl;
	settingsFile << "<Audio>" << endl;
	settingsFile << Audio << endl;
	settingsFile << "<END>" << endl;
	
	settingsFile.close(); //close file
}
void ExtendedDictionary::cheatle() { // cheating at wordle app
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);// this line and previous had to be reinitialised to display colours
	system("cls");
	int selectRow = 0; //vertical selection position
	int selectCol = 0;//horizontal selection position
	string keyboardKeys[3][11] = { {"q","w","e","r","t","y","u","i","o","p"},
								   {"a","s","d","f","g","h","j","k","l"," "},
								   {"z","x","c","v","b","n","m"," "," "," "} };//"keyboard"
	string keyboardBorder[9] = { R"(                                     -----------------------------------------)",
R"(                                     |   |   |   |   |   |   |   |   |   |   |)",
R"(                                     -----------------------------------------)",
R"(                                        -------------------------------------)",
R"(                                        |   |   |   |   |   |   |   |   |   |)",
R"(                                        -------------------------------------)",
R"(                                           -----------------------------)",
R"(                                           |   |   |   |   |   |   |   |)",
R"(                                           -----------------------------)" };//keyboard border

	string greyKeys = "";//empty set of keys
	string yellowKeys = "";
	string greenKeys = "";
	string greenTemp;
	bool greenCheck = true;//check to see if green key requirement is fulfilled
	bool yellowCheck = true; //check to see if yellow key requirement is fulfilled
	int n = 0; // index value of green keys
	string blankWordSpaced[10] = { "_", "_", "_", "_", "_", "_", "_", "_", "_", "_" }; //the 'skeleton' of the final word
	int wordLengthSave =0; //word length input (persistent)
	int wordLength = 0;//word length and letter positioning
	int colourKeys[3][11] = { { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
							  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
							  { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } };//colour key map
	bool keyboard = true; // the bool flag that handles quiting the game
	while (keyboard) {  //loop

		SetConsoleTextAttribute(hConsole, 15);
		if (wordLengthSave != 0) {
			wordLength = wordLengthSave;
		}
		SetConsoleTextAttribute(hConsole, 15);
		for (int k = 0; k < 9; k++) {
			printf("\033[%d;%dH", 4 + k, 1);
			std::cout << keyboardBorder[k];//keyboard print
		}
		printf("\033[%d;%dH", 1, 50); //title
		std::cout << "Wordle cheater!";
		printf("\033[%d;%dH", 3, 1); //title
		wordColour(4, 1, 3, 6, "Navigate with [Arrow] keys");
		wordColour(5, 1, 4, 14, "Toggle colour with [Space]");
		wordColour(6, 1, 2, 11, "Use [Number] keys to set word length");
		wordColour(7, 1, 2, 7, "(Use zero-key for 10 digit words)");
		wordColour(8, 1, 5, 4, "Restart/ Quit with the [Escape] Key.");
		wordColour(20,48, 2, 10, "Press [Enter] to confirm");

		wordColour(13, 1, 1, 128, "Grey letters: NOT in word.");
		wordColour(15, 1, 1, 96, "Yellow letters: in word in UNKNOWN position.");
		wordColour(17, 1, 1, 32, "Green letters: in word in KNOWN position.");

		printf("\033[%d;%dH", 3, 90); //title
		std::cout << "Word Length: " << wordLength<<"   ";
		if (wordLengthSave != 0) {
			printf("\033[%d;%dH", 3, 105);
			std::cout << "[Fixed]";
		}
		SetConsoleTextAttribute(hConsole, 15);
		for (int j = 0; j < 3; j++) { //standard keyboard
			for (int i = 0; i < 10; i++) {
				printf("\033[%d;%dH", 5 + j * 3, 40 + 4 * i + 3 * j);
				std::cout << keyboardKeys[j][i];
			}
		}
		for (int j = 0; j < 3; j++) {// key colouring print 
			for (int i = 0; i < 10; i++) {
				if (colourKeys[j][i] == 1) { //grey
					SetConsoleTextAttribute(hConsole, 128);
					printf("\033[%d;%dH", 5 + j * 3, 40 + 4 * i + 3 * j);
					std::cout << keyboardKeys[j][i];
				}
				if (colourKeys[j][i] == 2) { //yellow
					SetConsoleTextAttribute(hConsole, 96);
					printf("\033[%d;%dH", 5 + j * 3, 40 + 4 * i + 3 * j);
					std::cout << keyboardKeys[j][i];
				}
				if (colourKeys[j][i] == 3) { //green
					SetConsoleTextAttribute(hConsole, 32);
					printf("\033[%d;%dH", 5 + j * 3, 40 + 4 * i + 3 * j);
					std::cout << keyboardKeys[j][i];
				}
			}
		}					
		for (int j = 0; j < 3; j++) {// cursor print 
			for (int i = 0; i < 10; i++) {
				if (colourKeys[selectRow][selectCol] == 0) {//normal cursor
					SetConsoleTextAttribute(hConsole, 240);
				}
				if (colourKeys[selectRow][selectCol] == 1) {//grey cursor
					SetConsoleTextAttribute(hConsole, 143);
				}
				if (colourKeys[selectRow][selectCol] == 2) {//yellow cursor
					SetConsoleTextAttribute(hConsole, 111);
				}
				if (colourKeys[selectRow][selectCol] == 3) {//green cursor
					SetConsoleTextAttribute(hConsole, 47);
				}
				printf("\033[%d;%dH", 5 + selectRow * 3, 40 + 4 * selectCol + 3 * selectRow);
				std::cout << keyboardKeys[selectRow][selectCol];
			}
		}			
		int wordCount = 0;
		switch ((_getch())) { //registers key input
		case KEY_UP:
			if (!selectRow < 1) {//prevents going off keyboard
				selectRow -= 1;
			}
				OST(17, Audio);		
			break;
		case KEY_DOWN:
			if ((selectRow == 0 && selectCol < 9) || (selectRow == 1 && selectCol < 7)) {//prevents going off keyboard
				selectRow += 1;
			}
				OST(17, Audio);		
			break;
		case KEY_LEFT:
			if (!selectCol < 1) {//prevents going off keyboard
				selectCol -= 1;
			}
				OST(17, Audio);	
			break;
		case KEY_RIGHT:
			if ((selectCol < 9 && selectRow == 0) || (selectCol < 8 && selectRow == 1) || (selectCol < 6 && selectRow == 2)) {//prevents going off keyboard
				selectCol += 1;
			}
				OST(17, Audio);			
			break;
		case KEY_SPACE:
				if (colourKeys[selectRow][selectCol] == 0) {
					OST(22, Audio);
				}
				if (colourKeys[selectRow][selectCol] == 1) {
					OST(23, Audio);
				}
				if (colourKeys[selectRow][selectCol] == 2) {
					OST(24, Audio);
				}
				if (colourKeys[selectRow][selectCol] == 3) {
					OST(25, Audio);
				}
			
			if (colourKeys[selectRow][selectCol] != 3) {// toggles through colours
				colourKeys[selectRow][selectCol] += 1;
			}
			else {
				colourKeys[selectRow][selectCol] = 0;
			}
			break;
		case KEY_ENTER:
				OST(11, Audio);
			greenKeys = "";//prevents duplicates
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < 10; i++) {
					if (colourKeys[j][i] == 1) {
						greyKeys += keyboardKeys[j][i];//grabs grey keys from colour key map
					}
					if (colourKeys[j][i] == 2) {
						yellowKeys += keyboardKeys[j][i];//grabs yellow keys..
					}
					if (colourKeys[j][i] == 3) {
						greenKeys += keyboardKeys[j][i];//grabs green keys
					}
				}
			}
			yellowKeys += greenKeys;// ensures that green keys aren't excluded in yellow check
			SetConsoleTextAttribute(hConsole, 7);
			system("cls");

			if (wordLength == 0) {// if the length hasn't been input yet, it prompts you to enter
				cout << "What is the length of the word?\n";
				while(!(cin >> wordLengthSave)){
					cin.clear();
					cin.ignore();
					system("cls");
					cout << "Sorry, can you try again please? \n(Numberic input only)\n";
				}
			}
			else {
				wordLengthSave = wordLength;
			}
			if (wordLengthSave > 10) {
				wordLengthSave = 10;
				wordLength = 10;
			}
			selectCol = 0;
			for (int i = 0; i < wordLengthSave; i++) {
				printf("\033[%d;%dH", 8, 50);
				cout << "Here is your blank word: ";
			}
			n = 0;
			while (!(n >= greenKeys.length())) {// cycles through green keys

				printf("\033[%d;%dH", 12, 50);
				cout << "where should '" << greenKeys[n] << "' go?";
				printf("\033[%d;%dH", 13, 50);
				cout << "(If a character is green in multiple places, run again)";
				wordColour(8, 1, 4, 6, "Navigate with the [Left]");
				wordColour(8, 26, 2, 6, "and [Right] keys.");
				wordColour(9, 1, 5, 10, "Confirm letter position with [Enter]");
				wordColour(10, 1, 2, 14, "Use [Space] to clear a letter.");
				wordColour(11, 1, 2, 4, "Use [Escape] to skip to the next green letter.");
				for (int i = 0; i < wordLengthSave; i++) {
					printf("\033[%d;%dH", 10, 50 + i * 2);
					std::cout << blankWordSpaced[i];//presents 'skeleton' of green word
				}
				printf("\033[%d;%dH", 10, 50 + selectCol * 2);
				std::cout << greenKeys[n];//position green key letters

				switch ((_getch())) {// enables keyboard use again to move green letters
				case KEY_LEFT:
					if (!selectCol < 1) {
						selectCol -= 1;
					}
					break;
				case KEY_RIGHT:
					if (selectCol < wordLengthSave - 1) {
						selectCol += 1;
					}
					break;
				case KEY_ENTER:
					blankWordSpaced[selectCol] = greenKeys[n];
					n += 1;
					break;
				case KEY_SPACE:
					blankWordSpaced[selectCol] = "_";
					break;
				case KEY_ESCAPE:
					n +=1;
					break;
				}
			}
			greenTemp = ""; //prevents duplicate green letters being saved
			for (int i = 0; i < wordLengthSave; i++) {
				greenTemp += blankWordSpaced[i]; // writes green letter over 'skeleton'
			}
			system("cls");
			for (Word* w : words) { //loads all words from dictionary
				string word = w->getWord();
				if (word.size() != wordLengthSave) { //filters words by size
					continue;
				}
				bool greyCheck = true;
				for (char e : greyKeys) {
					if (word.find(e) != string::npos) { //filters word by grey letters (removes all words with grey letters)
						greyCheck = false;
						break;
					}
				}
				if (!greyCheck) { //passed the grey check
					continue;
				}
				bool yellowCheck = true;
				for (char y : yellowKeys) {
					if (word.find(y) == string::npos) { //filters words by yellow letters (removes all words WITHOUT yellow letters)
						yellowCheck = false;
						break;
					}
				}
				if (!yellowCheck) { // passed yellow check
					continue;
				}

				bool greenCheck = true;
				for (int i = 0; i < word.size(); i++) {
					if (greenTemp[i] != '_' && word[i] != greenTemp[i]) {//filters word by green letters (removes all words without green letters in the position they have been placed)
						greenCheck = false;
						break;
					}
				}
				if (!greenCheck) {//passed green check
					continue;
				}
				cout << word << endl;//prints all words that haven't been filtered out.
				wordCount += 1;
			}
			if (wordCount == 0) {
				cout << "I don't think I have the word you're looking for..\n\n";
			}
			if (wordCount == 1) {
				cout << "Looks like we've narrowed it down!\n";
				OST(9, Audio);
			}
			if (wordCount > 1) {
				cout << "Try one of these " << wordCount << " words, then we'll cheat better next round!\n";
			}
			system("pause");
			system("cls");
		case KEY_ZERO:
			wordLength = 10;
			break;
		case KEY_ONE:			//number input via keys
			wordLength = 1;
			break;
		case KEY_TWO:
			wordLength = 2;
			break;
		case KEY_THREE:
			wordLength = 3;
			break;
		case KEY_FOUR:
			wordLength = 4;
			break;
		case KEY_FIVE:
			wordLength = 5;
			break;
		case KEY_SIX:
			wordLength = 6;
			break;
		case KEY_SEVEN:
			wordLength = 7;
			break;
		case KEY_EIGHT:
			wordLength = 8;
			break;
		case KEY_NINE:
			wordLength = 9;
			break;
		case KEY_ESC: //escape key to quit
			SetConsoleTextAttribute(hConsole, 7);
			int restartSel = 0;
			string restart[2] = { "Restart?","Quit?" };
			system("cls");
			bool restartMenu = true;
			while(restartMenu){
				SetConsoleTextAttribute(hConsole, 7);
				for (int o = 0; o < 2; o++) {
					printf("\033[%d;%dH", 12, 45 + 25 * o);
					cout << restart[o];
				}
				SetConsoleTextAttribute(hConsole, 112);
				printf("\033[%d;%dH", 12, 45 + 25 * restartSel);
				cout << restart[restartSel];
			switch ((_getch())) {// enables keyboard use again to move green letters
			case KEY_LEFT:
				if (!restartSel < 1) {
					restartSel -= 1;
				}
				break;
			case KEY_RIGHT:
				if (restartSel < 2) {
					restartSel += 1;
				}
				break;
			case KEY_ENTER: {
				if (restartSel == 0) {
					SetConsoleTextAttribute(hConsole, 7);
					cheatle();
				}
				if (restartSel == 1) {
					SetConsoleTextAttribute(hConsole, 7);
					keyboard = false;
					restartMenu = false;
				}
				break;
			}
			}
			}
		}
	}
}
void  ExtendedDictionary::AudioToggle(){
	if (Audio ==2) {
		Audio = 0;
	}
	else {
		Audio += 1;
	}
}