#include <boost/bimap.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	bimap<int, std::string> bm;		//定义一个双向视图对象

	//使用左视图map<int, std::string>
	bm.left.insert(std::make_pair(1, "111"));		//插入数据
	bm.left.insert(std::make_pair(2, "222"));		

	//使用右视图map<std::string, int>
	bm.right.insert(std::make_pair("string", 10));		//插入数据
	bm.right.insert(std::make_pair("bimap", 20));	

	//对左视图使用迭代器迭代
	for(auto pos = bm.left.begin();
		pos != bm.left.end();++pos){
		std::cout << "left[" << pos->first << "]=" << pos->second << std::endl;
	}
	return 0;
}
	
