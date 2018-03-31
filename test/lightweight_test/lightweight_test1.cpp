#include <boost/smart_ptr.hpp>
#include <boost/core/lightweight_test.hpp>
#include <memory>

int main(){
	auto p = std::make_shared<int>(10);		//智能指针

	BOOST_TEST(*p == 10);				//测试解引用
	BOOST_TEST(p.unique());				//测试唯一性

	BOOST_TEST_EQ(p.use_count(), 1);	//相等测试
	BOOST_TEST_NE(*p, 20);				//不等测试

	p.reset();
	BOOST_TEST(!p);

	BOOST_TEST_THROWS(*p, std::runtime_error);		//测试抛出异常，失败
	BOOST_ERROR("error accured!!");					//输出错误信息

	return boost::report_errors();					//输出测试报告	
}

