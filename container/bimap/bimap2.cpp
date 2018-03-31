#include <boost/bimap.hpp>
#include <string>
#include <iostream>
using namespace boost::bimaps;

template<typename T>
void print_map(T &m){
	for(auto &x : m){
		std::cout << x.first << "<-->" << x.second << std::endl;
	}
}

int main(){
	bimap<tagged<int, struct id>, tagged<std::string, struct name> > bm;

	bm.by<id>().insert(std::make_pair(1, "samus"));		//使用标签"id"
	bm.by<id>().insert(std::make_pair(2, "adam"));		//相当于左视图

	bm.by<name>().insert(std::make_pair("link", 10));		//使用标签"name"
	bm.by<name>().insert(std::make_pair("zelda", 11));		//相当于右视图

	print_map(bm.by<name>());
	return 0;
}
