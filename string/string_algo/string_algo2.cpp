#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	std::string str("I Don't Know.\n");
	std::cout << to_upper_copy(str);		//返回大写的拷贝
	std::cout << str;			//原字符串不改变
	to_lower(str);				//字符串小写
	std::cout << str;			//原字符串改变
	return 0;
}
