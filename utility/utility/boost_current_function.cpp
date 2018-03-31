#include <boost/current_function.hpp>
#include <iostream>
#include <string>

double func(){
	std::cout << BOOST_CURRENT_FUNCTION << std::endl;
}

std::string str = BOOST_CURRENT_FUNCTION;		//错误用法，在函数作用域外无意义

int main(){
	std::cout << str << std::endl;
	std::cout << __FUNCTION__ << std::endl;
	std::cout << BOOST_CURRENT_FUNCTION << std::endl;
	func();
	return 0;
}
