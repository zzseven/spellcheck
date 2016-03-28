 ///
 /// @file    Diction.h
 /// @author  zzseven
 /// @date    2016-03-28 10:55:43
 ///
 
/*
 *
 * 这个类用于读取文件，创建好map<string, int>并存储在文件中
 *	由于文件比较复杂要进一步处理：将大写字符转换成小写，非字母字符转换成空格，保存到文件中。
 *
 *
*/


#ifndef _DICTION_H_
#define _DICTION_H_

#include <map>
#include <string>
#include <fstream>


using std::string;
using std::map;
using std::ofstream;
using std::ifstream;

namespace zz
{
class Diction
{
public:
	Diction();
	void loadDicToMap(const string &dictName);//从处理后的文件总读取数据，建立map
	void readFileToMap(const char * filename);//从原始文件读数据，并进行相应的处理
	void traverseDir(const char *row_path);   //遍历目录,获取当前源文件
	ofstream & open_file(ofstream &os, const char *filename); //打开输出文件，保存处理后的数据
	ifstream & open_file(ifstream &is, const char *filename); //打开输入文件，读取原始数据

public:
	map<string, int> & getDictMap();//获取词典

private:
	string dispose(string str);
	map<string, int> dict_map_; //词典
	
};


}


#endif
