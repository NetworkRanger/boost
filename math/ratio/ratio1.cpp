#define BOOST_RATIO_EXTENSIONS
#include <boost/ratio.hpp>
#include <iostream>
using namespace boost;

int main(){
	typedef ratio<1, 2> half;		//分数二分之一

	assert(half::num == 1);		//静态成员分子
	assert(half::den == 2);		//静态成员分母

	auto v = half::value();		//获得rational对象 
	std::cout << v << std::endl;
	assert(v*3 == 1);

	half frac;		//声明一个分数实例
	assert(frac().numerator() == frac.num);

	typedef ratio<2, 4> two_fourth;		//分数四分之二
	std::cout << two_fourth()() << std::endl;		//构造函数，再调用operator()
	assert(half::value() == two_fourth::value());

	typedef ratio<12> dozen;
	assert(2*dozen()() == 24);		//计算两打=24
	return 0;
}
