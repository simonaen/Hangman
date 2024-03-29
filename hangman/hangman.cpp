#include "pch.h"
#include <cctype>
#include "WordsVector.h"
using namespace std;

int main()
{
	//creates a vector and inserts words from file into vector

	WordsVector wordsVec;
	ifstream input("words.txt");
	wordsVec.storeWords(input);

	string random_word = wordsVec.pickRandom(); //get random word from vector
	int err = 0; //wrong guesses, start from 0
	const int MAX_ERR = 7; 	//maximum wrong guesses allowed
	string progress(random_word.size(), '-'); //copies random_word but every char in the string is a -
	string used_letters = "abcdefghijklmnopqrstuvwxyz"; //string of alphabet chars
	char guess; //player's "guess" each round


	/*while(){} Shows game progress(guessed letters in word and used letters from alphabet).
		If player picks anything but upper- or lowercase letters, loop starts again.
		Else, uppercase are converted to lower to match words in words.txt.
		If guess is found in the random_word string, progress variable and alphabet string are updated.
		Else, the number of wrong guesses (err) increases by one
		While(){} goes on while we still have some wrong guesses left and player hasn't guessed*/


PLAY:while ((err < MAX_ERR) && (progress != random_word)) {
	cout << "	Your progress so far: " << progress << endl;
	cout << "	Letters you've used: " << used_letters << endl;
	cout << "	Enter a letter: ";
	cin >> guess;
	if (!isalpha(guess)) {
		cout << endl;
		cout << "	You can only use letters" << endl;
		cout << endl;
		goto PLAY;
	}

	guess = tolower(guess);

	for (int i = 0; i <= used_letters.size(); i++) {
		if (used_letters[i] == guess)
			used_letters[i] = '-';
	}

	if (random_word.find(guess) != string::npos) {
		for (int i = 0; i < random_word.size(); i++) {
			if (random_word[i] == guess)
				progress[i] = guess;
		}
	}
	else
		++err;
}
	 //If player has more wrong guesses than allowed -> loss
	 if (err == MAX_ERR) {
		 cout << endl;
		 cout << "	Sorry, you're not a winner :/" << endl;
		 cout << " The word was: " << random_word << endl;
	 }
	 //If player guessed the word without surpassing MAX_ERRS -> win
	 else {
		 cout << endl;
		 cout << "	That's right, you guessed: " << random_word << endl;
	 }

	 return 0;
}
