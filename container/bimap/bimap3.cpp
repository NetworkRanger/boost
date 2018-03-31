#include <boost/bimap.hpp>
#include <boost/assign.hpp>
#include <iostream>
#include <string>

int main(){
	using namespace boost::bimaps;
	typedef bimap<int, std::string> bm_t;

	using namespace boost::assign;
	bm_t bm = list_of<bm_t::relation>(1, "mario")(2, "peach");		//使用relation作为元素类型初始化

	auto pos = bm.left.find(1);	//左视图查找键1
	std::cout << "[" << pos->first << "]=" << pos->second << std::endl;
	auto pos2 = bm.right.find("peach");		//右视图查找键值"peach"
	std::cout << "[" << pos2->first << "]" << pos2->second << std::endl;
	return 0;
}
