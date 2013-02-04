/****************************************************************
 * File: SearchCompositeWord.cpp
 * Description: Implementation for Class SearchCompositeWord.
 *
 * Lauguage: C++
 * System: Linux
 * Status: Serial Program, Version 1.0
 * Author: Yueying Cui
 * Date: 01/31/2013
******************************************************************/
#include "SearchCompositeWord.h"

bool compare(const string str1, const string str2){
	return str1.size() > str2.size();
}

/*
 * Function:	ParseFile
 * Description: Read words into 'words_map'.
 *		Sorted words by length into 'words'.
 * Parameter:	* file: file name
 * Return:	* -1: failed
 *		* 0: succeed
*/
int SearchCompositeWord::ParseFile(const string file){
	string word;
	ifstream fin(file.c_str());	
	if(!fin){
		cout << "Failed to open \"" << file << "\"." << endl;
		return -1;
	}
	
	// debug info
	cout << "Parsing words from \"" << file << "\"..." << endl;

	while(getline(fin, word)){	
		// debug info
		//cout << word << endl;

		istringstream stream(word);
		while(stream >> word){
			words.push_back(word);
			words_map[word] = true;
		}
	}

	sort(words.begin(), words.end(), compare);
	fin.close();	
	
	// debug info
	cout << "Parsing is done." << endl;

	return 0;
}

/*
 * Function:	FindCompositeWord
 * Description: Find the longest composite word.
 *		Save composite words into "CompositeWords.txt".
 * Parameter:	NA
 * Return:	NA
*/
void SearchCompositeWord::FindCompositeWord(){
	// debug info
	cout << "Searching composite words..." << endl;

	vector<string>::iterator viter;
	ofstream ofile("CompositeWords");

	for(viter = words.begin(); viter != words.end(); viter++ ){
		if(IsCompositeWord(*viter)){
			ofile << *viter <<endl;
			count++;
			// updated longest_composed_word, longest_composed_word_length
			if(longest_composite_word_length < ((string)(*viter)).length()){
            			longest_composite_word_length = ((string)*viter).length() ;
            			longest_composite_word = *viter;
         		}
      		}
   	} 
	
	ofile.close();

	// debug info
	cout << "Searching is done." << endl;

  	return;
}

/*
 * Function:	IsCompositeWord
 * Description: Find the longest composite word.
 *		Save composite words into "ComposedWords.txt".
 * Parameter:	word: single word
 * Return:	* true: it is a composite word
 *		* false: it is not a composite word
*/
bool SearchCompositeWord::IsCompositeWord(string word){

	int n = word.length();
	int i;

	for(i = 1; i < n; i++){
		string head = word.substr(0, i);
		string tail = word.substr(i,n-i);
		if(words_map.find(head) != words_map.end() && (words_map.find(tail) != words_map.end() || IsCompositeWord(tail)))
			return true;
  	}

	return false;
}

/*
 * Function:	DisplayResult
 * Description: Display result for searching composite words.
 * Parameter:	NA
 * Return:	NA
*/
void SearchCompositeWord::DisplayResult(){
	if(longest_composite_word != " "){
		cout << "---------------------Results------------------------" << endl;
		cout << "The longest composite word:  " << longest_composite_word << endl;	
		cout << "Length:  " << longest_composite_word_length << endl;
		cout << "Number of composite words:  " << count << endl;
		cout << "Composite Words are saved in \"CompositeWords.txt\"" << endl;
	}
	else
		cout << "There isn't any word constructed by other words." << endl;	
}

