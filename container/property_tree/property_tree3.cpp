#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>	//json头文件
#include <iostream>
#include <string>

int main(){
	using namespace boost::property_tree;

	ptree pt;
	read_json("conf.json", pt);

	std::cout << pt.get<std::string>("conf.theme") << std::endl;
	std::cout << pt.get<int>("conf.clock_style") << std::endl;
	std::cout << pt.get<long>("conf.gui") << std::endl;
	std::cout << pt.get("conf.no_prop", 100) << std::endl;

	for(auto x : pt.get_child("conf.urls")){
		std::cout << x.second.data() << ", ";
	}
	return 0;
}
