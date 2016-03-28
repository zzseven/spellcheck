 ///
 /// @file    Diction.cc
 /// @author  zzseven
 /// @date    2016-03-28 11:33:42
 ///
 
#include "Diction.h"
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>

using std::vector;

namespace zz
{
Diction::Diction()
: dict_map_()
{

}

void Diction::loadDicToMap(const string &dictName)
{
	ifstream is(dictName.c_str());
	if(!is.good())
	{
		std::cout << "sdfsdfsdf" << std::endl;
		readFileToMap("aaa.txt");
		return ;
	}
	string line;
	char key[100];
	string word;
	int value;
	while(getline(is, line))
	{
		memset(key, 0, sizeof(key));
		sscanf(line.c_str(), "%s  %d", key, &value);
		word = key;
		dict_map_.insert(make_pair(word, value));
	}

	map<string, int>::iterator it;
	for(it = dict_map_.begin(); it!= dict_map_.end(); ++it)
	{
	//	std::cout << it->first << " " << it->second << std::endl;
	}
	is.close();	
}

void Diction::readFileToMap(const char * filename)
{
	ifstream is;
	ofstream os;
	open_file(is, filename); //打开原文件
	open_file(os, "string.txt");
	string line;
	string word;
	map<string, int>::iterator found;
	while(getline(is, line))
	{
		line = dispose(line); //得到处理后的行数据
		std::stringstream ss(line); //将字符串放入字符流ss
		while(ss >> word)  //分词
		{
			found = dict_map_.find(word);
			if(found != dict_map_.end())
			{
				found->second ++;
			}else
			{
				dict_map_.insert(make_pair(word, 1));
			}
		}
	}

	map<string, int>::iterator it;
	for(it = dict_map_.begin(); it != dict_map_.end(); ++it)
	{
		os << it->first << "  " << it->second << std::endl; 
	}
	is.close();
	os.close();


}

string Diction::dispose(string str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
	int len = strlen(str.c_str());
	for(int i=0; i<len; ++i)
	{
		if('a'<=str[i] && str[i] <= 'z')
		{
			
		}else
			str[i] = ' ';
	}
	return str;
}


void Diction::traverseDir(const char * row_path)
{
	DIR *dir;
	if(!(dir = opendir(row_path)))
	{
		std::cout << "open row_path error!" << std::endl;
		exit(-1);
	}

	struct dirent *d_ent;
	char funllpath[128];
	while((d_ent = readdir(dir)) != NULL)
	{
		struct stat file_stat;
		if(strcmp(d_ent->d_name, ".") == 0)
		{
			continue;

		}else if(strcmp(d_ent->d_name, "..") == 0)
		{
			continue;
		}

		std::cout << d_ent->d_name << std::endl;
	}
}

ofstream & Diction::open_file(ofstream &os, const char *filename)
{
	os.close();
	os.clear();
	os.open(filename, std::ios::app);
	if(!os.good())
	{
		std::cout << "ofstream open error!" << std::endl;
		exit(-1);
	}
	std::cout << "os open ok" << std::endl;
	return os;

}

ifstream & Diction::open_file(ifstream &is, const char *filename)
{
	is.close();
	is.clear();
	is.open(filename);
	if(!is.good())
	{
		std::cout << "ifstream open error!" << std::endl;
		exit(-1);
	}
	std::cout << "open if ok!" << std::endl;
	return is;
}

map<string, int>& Diction::getDictMap()
{
	return  dict_map_;
}	




}

