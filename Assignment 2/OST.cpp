#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#include "OST.h"
#include "ExtendedDictionary.h"
using namespace std;
int song;
int toggle;
void OST(int song, int toggle) {

	if (toggle == 0) { //mute
		PlaySound(NULL, NULL, 0);
	}
	if (toggle == 1) { //SFX
		switch (song) {
		case 6: {
			PlaySound(TEXT("Jeopardy-Theme.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			break;
		}
		case 7: {
			PlaySound(TEXT("wowowowowowowow.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 8: {
			PlaySound(TEXT("bell.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 9: {
			PlaySound(TEXT("you_win.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 10: {
			PlaySound(TEXT("wrong.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 11: {
			PlaySound(TEXT("click.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 12: {
			PlaySound(TEXT("lightning-strike-1.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 13: {
			PlaySound(TEXT("lightning-strike-2.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 14: {
			PlaySound(TEXT("lightning-strike-3.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 15: {
			PlaySound(TEXT("lightning-strike-4.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 16: {
			PlaySound(TEXT("Lightning title.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 17: {
			PlaySound(TEXT("click2.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 18: {
			PlaySound(TEXT("boop.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 19: {
			PlaySound(TEXT("bip.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 20: {
			PlaySound(TEXT("boop2.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 21: {
			PlaySound(TEXT("boop3.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 22: {
			PlaySound(TEXT("bing1.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 23: {
			PlaySound(TEXT("bing2.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 24: {
			PlaySound(TEXT("bing3.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 25: {
			PlaySound(TEXT("bing4.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 26: {
			PlaySound(TEXT("load_dictionary.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 27: {
			PlaySound(TEXT("word_search.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 28: {
			PlaySound(TEXT("multiple_char_checker.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 29: {
			PlaySound(TEXT("add_word.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 30: {
			PlaySound(TEXT("palindrome.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 31: {
			PlaySound(TEXT("rhyming.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 32: {
			PlaySound(TEXT("word_guess.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 33: {
			PlaySound(TEXT("cheatle.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 34: {
			PlaySound(TEXT("options.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 35: {
			PlaySound(TEXT("THX.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 36: {
			PlaySound(TEXT("title_on.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 37: {
			PlaySound(TEXT("title_off.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 38: {
			PlaySound(TEXT("high_score_clear.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 39: {
			PlaySound(TEXT("audio_off.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 40: {
			PlaySound(TEXT("SFX.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 41: {
			PlaySound(TEXT("music.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 42: {
			PlaySound(TEXT("loading.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			break;
		}
		case 43: {
			PlaySound(TEXT("done.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 44: {
			PlaySound(TEXT("autoloaden.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 45: {
			PlaySound(TEXT("autoloaddis.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 46: {
			PlaySound(TEXT("quiter.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 47: {
			PlaySound(TEXT("mainmenu.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 48: {
			PlaySound(TEXT("lets_go.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		case 49: {
			PlaySound(TEXT("Typewriter.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		}
		}
	}
	if (toggle == 2) { //music
		switch (song) {
		case 1: {
			PlaySound(TEXT("Orange.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			break;
		}
		case 2: {
			PlaySound(TEXT("menu.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			break;
		}
		case 3: {
			PlaySound(TEXT("cheat.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			break;
		}
		case 5: {
			PlaySound(TEXT("Wii-Shop_menu_.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
			break;
		}
		}
	}
}

