#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	std::string str("Samus||samus||mario||||Link");

	//查找迭代器类型定义
	typedef find_iterator<std::string::iterator> string_find_iterator;

	string_find_iterator pos, end;			//声明查找迭代器变量

	for(pos = make_find_iterator(str, first_finder("samus", is_iequal()));pos != end;++pos){
		std::cout << "[" << *pos << "] ";
	}
	std::cout << std::endl;

	//分割器迭代器类型定义
	typedef split_iterator<std::string::iterator> string_split_iterator;

	string_split_iterator p, endp;			//声明分割迭代器变量
	for(p = make_split_iterator(str, first_finder("||", is_iequal()));p != endp;++p){
		std::cout << "[" << *p << "]";
	}
	std::cout << std::endl;
	return 0;
}
