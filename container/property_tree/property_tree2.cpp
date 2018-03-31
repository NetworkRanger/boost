#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <iostream>

int main(){
	using namespace boost::property_tree;

	ptree pt;
	read_xml("conf.xml", pt);
	
	pt.put("conf.theme", "Matrix Reloaded");
	pt.put("conf.clock_style", 12);
	pt.put("conf.gui", 0);
	pt.put("conf.urls.url", "http://www.url4.org");
	
	write_xml(std::cout, pt);
	return 0;
}
