#include <boost/foreach.hpp>
#include <boost/assign.hpp>
#include <vector>
#include <iostream>
#include <string>

int main(){
	using namespace boost::assign;	//用assign初始化序列值
	std::vector<int> v = (list_of(1), 2, 3, 4, 5);		//boost::assign

	BOOST_FOREACH(auto x, v){
		std::cout << x << ",";
	}
	std::cout << std::endl;

	std::string str("boost foreach");
	BOOST_FOREACH(auto &c, str){
		std::cout << c << "-";
	}
	return 0;
}
