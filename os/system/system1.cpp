#include <boost/system/error_code.hpp>
#include <iostream>
using namespace boost::system;

int main(){
	std::cout << system_category().name() << std::endl;		//输出类别名称

	error_code ec;		//默认构造一个错误代码对象
	assert(ec.value() == errc::success);		//默认无错误
	assert(!ec);	//默认无错误,可bool转换
	assert(ec.category() == system_category());

	ec.assign(3L, system_category());		//错误值为3
	auto econd = ec.default_error_condition();		//产生一个可移植的错误代码
	assert(econd == ec);	//比较操作

	//也可直接用system_category产生可移植的错误代码
	assert(econd == system_category().default_error_condition(3L));

	std::cout << ec.message() << std::endl;		//输出错误描述信息
	std::cout << econd.message() << std::endl;	
	std::cout << econd.value() << std::endl;	//输出可移植的错误代码
	
	return 0;
}
