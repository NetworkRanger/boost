#include <boost/unordered_map.hpp>
#include <boost/assign.hpp>
#include <string>
#include <iostream>
using namespace boost;

int main(){
	using namespace boost::assign;

	unordered_map<int, std::string> um = map_list_of(1, "one")(2, "two")(3, "three");	//使用assign初始化
	
	um.insert(std::make_pair(10, "ten"));		//可以使用insert()函数
	std::cout << um[10] << std::endl;		//使用operator[]访问元素
	um[11] = "eleven";						//关联数组用法
	um[15] = "fifteen";						

	auto p = um.begin();					//使用auto获得迭代器
	for(;p != um.end();++p){
		std::cout << p->first << "-" << p->second << ", ";
	}
	std::cout << std::endl;

	um.erase(11);		//删除键值为11的元素
	std::cout << um.size() << std::endl;		//输出5
	return 0;
}
