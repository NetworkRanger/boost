#include <boost/multiprecision/cpp_dec_float.hpp>	//高精度数字库
#include <boost/math/constants/constants.hpp>
#include <iostream>
using namespace boost::math;

int main(){
	using namespace constants;

	assert(pi<float>() == float_constants::pi);		//模版函数获pi值
	assert(pi<double>() == double_constants::pi);		//double精度

	//使用boost.multiprecision库的高精度浮点数
	typedef boost::multiprecision::cpp_dec_float_100 float_100;

	std::cout << std::setprecision(100) << pi<float_100>() << std::endl;	//设置精度为100位，100位浮点小数
	return 0;
}
