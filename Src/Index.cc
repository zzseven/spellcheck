 ///
 /// @file    Index.cc
 /// @author  zzseven
 /// @date    2016-03-28 17:27:36
 ///
 
#include "Index.h"
#include "Diction.h"
#include <iostream>

namespace zz
{


Index::Index()
{
	vec_dict_.clear();
	dict_index_.clear();
}

void Index::loadDiction()
{
	map<string, int> dict_map;
	map<string, int> temp;
	string ss = "string.txt";
	dict_.loadDicToMap(ss);
	dict_map = dict_.getDictMap();
	map<string, int>::iterator it;
	for(it = dict_map.begin(); it!= dict_map.end(); ++it)
	{
		temp.clear();
		cout << it->first << "  " << it->second << endl;
		temp.insert(make_pair(it->first, it->second));
		vec_dict_.push_back(temp);
	}

	cout << endl << endl;
	vector<map<string, int> >::iterator kk;
	map<string, int>::iterator tt;
	for(kk = vec_dict_.begin(); kk != vec_dict_.end(); ++kk)
	{
		tt = (*kk).begin();
		cout << "vec:" << tt->first << " " << tt->second << endl;
	}

}

void Index::buildIndex()
{
	set<string> split;
	split.clear();
	vector<int> temp;

	vector<map<string, int> >::iterator kk; 
	map<string, int>::iterator tt;

	set<string >::iterator dd;
	map<string, vector<int> >::iterator found;
	int num = 0;
	for(kk = vec_dict_.begin(); kk != vec_dict_.end(); ++kk, ++num)
	{
		cout << "num = " <<  num << endl;
		tt = (*kk).begin();
		split = splitword(tt->first);
		for(dd = split.begin(); dd != split.end(); ++dd)
		{
			temp.clear();
			cout << "zifu: " << (*dd) << endl;
			found = dict_index_.find(*dd);
			if(found != dict_index_.end())
			{
				cout << "num1 = " <<  num << endl;
				found->second.push_back(num);

			}else
			{
				cout << "num2 = " <<  num << endl;
				temp.push_back(num);
				dict_index_.insert(make_pair(*dd, temp));
				cout << "ok !" <<endl;
			}
		}
	}

	map<string, vector<int> >::iterator hh;
	vector<int>::iterator cc;
	for(hh = dict_index_.begin(); hh!= dict_index_.end(); ++hh)
	{
		cout << "map: " << hh->first << "  ";

		for(cc = hh->second.begin(); cc != hh->second.end(); ++cc)
		//for(int n : hh->second)
		{
			cout << (*cc) << ", ";
		}
		cout << endl;
		
	}
	
	


}

set<string> Index::splitword(string word)
{
	set<string> cha;
	string temp;
	int len = word.length();		
	for(int i = 0; i<len; i++)
	{
		temp = word[i];
		cha.insert(temp);
	}
	return cha;

}




}
