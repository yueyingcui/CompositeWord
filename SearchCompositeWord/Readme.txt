Algorithm: 
	Dynamic Programming
	Status Transforring Formula: 
		check(word(n)) = check(word.substr(0, i)) && check(word.substr(i,n-i));

====================
Command Line Instruction: 
	$make
	$./main

====================
Results:
	Parsing words from "words_for_problem.txt"...
	Parsing is done.
	Searching composite words...
	Searching is done.
	---------------------Results------------------------
	The longest composite word:  ethylenediaminetetraacetates
	Length:  28
	Number of composite words:  97107
	Composite Words are saved in "CompositeWords.txt"
	Timer: 3s.
====================
Welcome all suggestions to my algorithm and coding. 
Please send your review to my email: yueying.cui@gmail.com
Thank you.

