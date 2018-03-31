#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <list>
#include <deque>
using namespace boost;

int main(){
	std::string str = "Samus, Link, Zelda::Mario-Luigi+zelda";

	std::deque<std::string> d;
	ifind_all(d, str, "zELDA");		//大小写无关分割字符串
	assert(d.size() == 2);
	for(auto x : d){
		std::cout << "[" << x << "] ";
	}
	std::cout << std::endl;

	std::list<iterator_range<std::string::iterator> > l;		//存储range对象
	split(l, str, is_any_of(",.:-+"));		//使用标点分割
	for(auto x : l){
		std::cout << "[" << x << "]";
	}
	std::cout << std::endl;

	l.clear();
	split(l, str, is_any_of(",:-"), token_compress_on);
	for(auto x : l){
		std::cout << "[" << x << "]";
	}
	std::cout << std::endl;

	return 0;
}
