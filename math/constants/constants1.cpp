#include <boost/math/constants/constants.hpp>
#include <iostream>
using namespace boost::math;

int main(){
	std::cout << std::setprecision(64);	//设置显示精度为64位

	auto a = float_constants::pi * 2 * 2;	//float精度的pi
	std::cout << "area = " << a << std::endl;

	using namespace double_constants;	//使用double精度
	auto x = root_two * root_three; 
	std::cout << "roo 2 * 3 = " << x << std::endl;
	
	std::cout << "root pi = " << root_pi << std::endl;
	std::cout << "pi pow e = " << pi_pow_e << std::endl;
	return 0;
}
