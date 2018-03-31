#include <boost/version.hpp>	//包含Boost头文件
#include <boost/config.hpp>
#include <iostream>

int main(){
	std::cout << BOOST_VERSION << std::endl;			//Boost 版本号
	std::cout << BOOST_LIB_VERSION << std::endl;		//Boost 版本号
	std::cout << BOOST_PLATFORM << std::endl;			//操作系统
	std::cout << BOOST_COMPILER << std::endl;			//编译器
	std::cout << BOOST_STDLIB << std::endl;			//标准库
	return 0;
}
