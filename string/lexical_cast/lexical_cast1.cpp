#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	int x = lexical_cast<int>("100");			//字符串->整数
	long y = lexical_cast<long>("2000");		//字符串->长整数
	float pai = lexical_cast<float>("3.14159e5");		//字符串->float
	double e = lexical_cast<double>("2.71828");			//字符串->double
	double r = lexical_cast<double>("1.414,x", 5);		//C字符串->double

	std::cout << x << pai << e << r << std::endl;

	std::string str = lexical_cast<std::string>(456);		//整数->字符串
	std::cout << str << std::endl;

	std::cout << lexical_cast<std::string>(0.618) << std::endl;		//float->字符串
	std::cout << lexical_cast<std::string>(0x10) << std::endl;		//16进制整数->字符串
	return 0;
}
