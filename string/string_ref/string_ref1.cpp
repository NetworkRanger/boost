#include <boost/utility/string_ref.hpp>
#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>
using namespace boost;

int main(){
	const char *ch = "Apple iPhone iPad";		//字符数组
		
	string_ref str(ch);			//创建字符串引用

	assert(!str.empty());		//是否为空字符串
	assert(str.size() == strlen(ch)); //获取长度

	for(auto &x : str){		//支持新式for循环
		std::cout << x;
	}
	std::cout << std::endl;

	assert(str.front() == 'A');			//类似容器的操作
	assert(str[1] == 'p');

	assert(str.find('i') == 6);			//简单的查找操作

	auto substr = str.substr(6, 6);		//获取子串，仍然是引用
	assert(substr == "iPhone");			//与标准字符串比较

	std::string s = str.to_string();	//转换为标准字符串
	assert(str == s);					//与标准字符串比较

	str.clear();						//清空字符串
	assert(str.empty());
	return 0;
}
