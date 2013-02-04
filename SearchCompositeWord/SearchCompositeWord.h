/****************************************************************
 * File: SearchCompositeWord.h
 * Description: Head file for Class SearchCompositeWord.
 *
 * Lauguage: C++
 * System: Linux
 * Status: Serial Program, Version 1.0
 * Author: Yueying Cui
 * Date: 01/31/2013
******************************************************************/
#ifndef SCW_H
#define SCW_H *

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class SearchCompositeWord{
	private:
		// words sorted by length
		vector<string> words;
		// words sorted by alphabetical order
		map<string, bool> words_map;
		// result
		string longest_composite_word;
		int longest_composite_word_length;
		int count;
	public:
		/* Constructor. */
		SearchCompositeWord(void){longest_composite_word = " "; longest_composite_word_length = 0; count = 0;}

		// parse words from file
		int ParseFile(const string file);
		// Core functions
		void FindCompositeWord(void);
		bool IsCompositeWord(string word);
		// display result
		void DisplayResult();

		/* Destructor. */
		~SearchCompositeWord(void){};
};

#endif // SCW_H
