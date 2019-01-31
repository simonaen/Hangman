//ArrVector expansion to suit Hangman needs
#pragma once
#include "ArrVector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
using namespace std;


class WordsVector{
public:
	WordsVector();
	void storeWords(ifstream& input); //store words from ifstream
	string pickRandom(); // selects random word from vector
private:
	ArrVector<string> wordsVec; //vector of words
	int n; //size
	//random function variables
	random_device randD;
	mt19937 randG;
	uniform_int_distribution<int> randN;
};

WordsVector::WordsVector() :n(0), randG(randD()) {
	randG.seed(time(nullptr));
}

void WordsVector::storeWords(ifstream& input) {
	string curr;
	while (input >> curr) {
		wordsVec.insert(curr);
		n++;
	}
	randN = uniform_int_distribution<>(1, n);
}

string WordsVector::pickRandom() {
	return wordsVec.elementAtRank(randN(randG));
}
