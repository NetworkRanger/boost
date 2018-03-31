#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	std::string str("readme.txt");		//一个标准字符串

	if(ends_with(str, "txt")){
		std::cout << to_upper_copy(str) + " UPPER" << std::endl;		//判断后缀
		assert(ends_with(str, "txt"));
	}

	replace_first(str, "readme", "followme");		//替换
	std::cout << str << std::endl;

	std::vector<char> v(str.begin(), str.end());		//一个字符的vector
	std::vector<char> v2 = to_upper_copy(erase_first_copy(v, "txt"));		//删除字符串
	for(auto ch : v2){
		std::cout << ch;
	}
	return 0;
}
