/****************************************************************
 * File: main.cpp
 * Description: Main file for searching composite words.
 *
 * Lauguage: C++
 * System: Linux
 * Status: Serial Program, Version 1.0
 * Author: Yueying Cui
 * Date: 01/31/2013
******************************************************************/
#include <iostream>
#include "SearchCompositeWord.h"
#include <time.h>

/*
 * Function: 	main
 * Description: main function
 * Parameter: 	* argv[1]: filename
 * Return:	* 0: failed
 *		* 1: succeed	
*/
int main(int argc, char *argv[]){
	// timer begin
	time_t seconds_begin, seconds_end;
	seconds_begin = time(NULL);

	SearchCompositeWord s;
	string filename = (argc ==2)?argv[1]:"words_for_problem.txt";
	int r;

	r = s.ParseFile(filename);	
	if(r < 0)
		return 0;
	s.FindCompositeWord();
	s.DisplayResult();

	// timer end	
	seconds_end = time(NULL);
	cout << "Timer: " << seconds_end - seconds_begin << "s."<< endl;
	return 1;
}
