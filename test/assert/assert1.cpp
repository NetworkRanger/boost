#include <boost/assert.hpp>

double func(int x){		//取倒数的函数
	BOOST_ASSERT_MSG(x != 0, "divided by zero");	//断言参数非0
	return 1.0 / x;
}
