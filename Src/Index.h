 ///
 /// @file    Index.h
 /// @author  zzseven
 /// @date    2016-03-28 16:25:53
 ///
 
#ifndef _INDEX_H_
#define _INDEX_H_

#include "Diction.h"
#include <vector>
#include <map>
#include <set>
#include <iostream>


using std::vector;
using std::string;
using std::map;
using std::cout;
using std::endl;
using std::set;


namespace zz
{
class Index
{
public:
	Index();
	void loadDiction();
	void buildIndex();
	set<string> splitword(string word);

public:
	Diction dict_;	
	vector<map<string, int> > vec_dict_;
	map<string, vector<int> > dict_index_;






};


}


#endif
