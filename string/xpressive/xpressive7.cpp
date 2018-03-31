#include <boost/xpressive/xpressive_dynamic.hpp>
#include <iostream>
#include <string.h>

int main(){
	using namespace boost::xpressive;

	char str[] = "*Link*||+Mario+||Zelda!!!||Metriod";

	//查找所有的单词，忽然标点符号
	cregex reg = cregex::compile("\\w+", icase);

	cregex_token_iterator pos(str, str+strlen(str), reg);
	for(;pos!=cregex_token_iterator();++pos){
		std::cout << "[" << *pos << "]";
	}
	std::cout << std::endl;

	//使用分隔符正则表达式，分隔是“||”
	cregex split_reg = cregex::compile("\\|\\|");
	pos = cregex_token_iterator(str, str+strlen(str), split_reg, -1);
	for(;pos != cregex_token_iterator();++pos){
		std::cout << "[" << *pos << "]";
	}
	std::cout << std::endl;
	return 0;
}
