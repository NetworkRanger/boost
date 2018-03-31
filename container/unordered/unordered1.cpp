#include <boost/unordered_set.hpp>		//boost散列集合
#include <iostream>
using namespace boost;

int main(){
	unordered_set<int> s = {1, 2, 3, 4, 5};		//初始化数据

	for(auto x : s){
		std::cout << x << " ";			//使用for遍历集合
	}
	std::cout << std::endl;
	std::cout << s.size() << std::endl;		//获取容器大小

	s.clear();		//清空集合
	std::cout << s.empty() << std::endl;		//判断集合是否为空

	s.insert(8);		//使用insert()函数
	s.insert(45);	
	std::cout << s.size() << std::endl;
	std::cout << *s.find(8) << std::endl;		//查找元素

	s.erase(45);
	return 0;
}
