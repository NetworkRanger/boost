#define BOOST_TEST_MAIN					//必须定义测试套件
#include <boost/test/unit_test.hpp>		//test库头文件
#include <boost/smart_ptr.hpp>
using namespace boost;

BOOST_AUTO_TEST_SUITE(s_smart_ptr);		//开始测试套件s_smart_ptr

BOOST_AUTO_TEST_CASE(t_scoped_ptr){		//测试用命1： t_scoped_ptr
	scoped_ptr<int> p(new int(874));
	BOOST_CHECK(p);		//p不是空指针
	BOOST_CHECK_EQUAL(*p, 874);	//测试解引用值
	
	p.reset();		//scoped_ptr复位
	BOOST_CHECK(p == 0);		//为空指针
}

BOOST_AUTO_TEST_CASE(t_shared_ptr){		//测试用命2： t_shared_ptr
	shared_ptr<int> p (new int(100));

	BOOST_CHECK(p);		//p不是空指针
	BOOST_CHECK_EQUAL(*p, 100);	//测试解引用值
	BOOST_CHECK_EQUAL(p.use_count(), 1);		//引用计数1

	shared_ptr<int> p2 = p;		//拷贝构造另一个shared_ptr
	BOOST_CHECK_EQUAL(p, p2);	//两个shared_ptr必定相等
	BOOST_CHECK_EQUAL(p2.use_count(), 2);		//引用计数2
	
	*p2 = 255;		//改变第二个shared_ptr所指的内容
	BOOST_CHECK_EQUAL(*p, 255);		//第一个所指的内容也同时改变
	BOOST_CHECK_GT(*p, 200);
}

BOOST_AUTO_TEST_SUITE_END()			//结果测试套件
