#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <iostream>
#include <vector>
using namespace boost;

//全局测试夹具类
struct global_fixture{
	global_fixture(){
		std::cout << ("global setup\n");
	}
	~global_fixture(){
		std::cout << ("global teardown\n");
	}
};

//定义全局夹具
BOOST_GLOBAL_FIXTURE(global_fixture);

//测试套件夹具类
struct assign_fixture{
	assign_fixture(){
		std::cout << ("suit setup\n");
	}
	~assign_fixture(){
		std::cout << ("suit teaddown\n");
	}

	std::vector<int> v;	//所有测试用例都可用的成员变量
};

//定义测试套件级别的夹具
BOOST_FIXTURE_TEST_SUITE(s_assign, assign_fixture)

BOOST_AUTO_TEST_CASE(t_assign1){		//测试+=操作符
	using namespace boost::assign;

	v += 1, 2, 3, 4;
	BOOST_CHECK_EQUAL(v.size(), 4);
	BOOST_CHECK_EQUAL(v[2], 3);
}

BOOST_AUTO_TEST_CASE(t_assign2){		//测试push_back函数
	using namespace boost::assign;

	push_back(v)(10)(20)(30);

	BOOST_CHECK_EQUAL(v.empty(), false);
	BOOST_CHECK_LT(v[0], v[1]);
}

BOOST_AUTO_TEST_SUITE_END()		//测试套件结束




























