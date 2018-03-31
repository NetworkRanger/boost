#define BOOST_DISABLE_ASSERTS		//注意这里
#include <cassert>					//标准断言头文件
#include <boost/assert.hpp>			//标准boost断言头文件

double func(int x){
	BOOST_ASSERT(x != 0 && "divided by zero");		//失效
	std::cout << "after BOOST_ASSERT" << std::endl;

	assert(x != 0 && "divided by zero");			//有效
	std::cout << "after assert" << std::endl;

	return 1.0 / x;
}
