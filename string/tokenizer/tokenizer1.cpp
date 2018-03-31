#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	std::string str("Link raise the master-sword.");

	tokenizer<> tok(str);			//使用缺省模板参数创建分词对象

	//可以像遍历一个容器一样使用for循环获得分词结果
	for(auto &x : tok){				//或者是BOOST_FOREACH(auto &x, tok)
		std::cout << "[" << x << "]";
	}
	std::cout << std::endl;
	return 0;
}
