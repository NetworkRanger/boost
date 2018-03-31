#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>
#include <string>

int main(){
	using namespace boost::property_tree;

	ptree pt;		//声明property_tree
	read_xml("conf.xml", pt);	//解析xml配置文件

	//示范get<>()函数的用法
	std::cout << pt.get<std::string>("conf.theme") << std::endl;
	std::cout << pt.get<int>("conf.clock_style") << std::endl;
	std::cout << pt.get<long>("conf.gui") << std::endl;
	std::cout << pt.get("conf.no_prop", 100) << std::endl;	//缺省值用法

	for(auto &x : pt.get_child("conf.urls")){
		std::cout << x.second.data() << ", ";		//改用data()函数	
	}
	std::cout << std::endl;
	return 0;
}
