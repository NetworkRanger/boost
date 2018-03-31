#include <boost/format.hpp>
#include <boost/test/minimal.hpp>		//最小化测试头文件
#include <iostream>

int test_main(int argc, char **argv){
	using namespace boost;
	format fmt("%d-%d");

	BOOST_CHECK(fmt.size() != 0);		//断言format对象已经初始化
	fmt % 12 % 34;
	BOOST_REQUIRE(fmt.str() == "12-34");		//验证格式化结果

	BOOST_ERROR("演示一条错误信息");			//不影响程序的执行

	fmt.clear();
	fmt % 12;
	try{
		std::cout << fmt;
	}catch(...){
		BOOST_FAIL("致使错误，测试终止");
	}
	return 0;							//与main不同，必须返回值
}
	
