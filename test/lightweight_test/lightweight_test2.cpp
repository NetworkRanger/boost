#include <type_traits>
#include <boost/core/lightweight_test_trait.hpp>

int main(){
	BOOST_TEST_TRAIT_TRUE((is_integral<int>));		//int是整数，注意圆括号
	BOOST_TEST_TRAIT_TRUE((is_function<int>));		//int不是函数

	return boost::report_errors();
}
