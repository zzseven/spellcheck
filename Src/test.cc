 ///
 /// @file    test.cc
 /// @author  zzseven
 /// @date    2016-03-28 12:53:46
 ///
 
#include "Index.h"
#include <iostream>
using namespace zz;
using namespace std;

int main()
{
#if 0
	Diction cs;
	cs.traverseDir(".");
	std::ifstream is;
	///const char filename[20] = "a.out";
	cs.open_file(is, "Diction.h");

	string word;
	while(is >> word)
	{
		cout << word << endl;
	}

	ofstream os;
	cs.open_file(os, "a.txt");

	os << "hello world!" << endl;
	string ss = "string.txt";
	cs.loadDicToMap(ss);

#endif

	Index ss;
	ss.loadDiction();
	ss.buildIndex();





}
