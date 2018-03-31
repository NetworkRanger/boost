#include <boost/serialization/singleton.hpp>
#include <iostream>
using boost::serialization::singleton;

int main(){
	std::cout << "main() start" << std::endl;
	typedef singleton<point> origin;			//单件类的定义

	origin::get_const_instance().print();		//常对象
	origin::get_mutable_instance().print();		//可变对象

	std::cout << "main() finish" << std::endl;
	return 0;
}
