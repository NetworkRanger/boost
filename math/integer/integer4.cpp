#include <boost/integer.hpp>
#include <boost/type_index.hpp>		//使用type_index库
#include <iostream>
using namespace boost;

int main(){
	typedef int_fast_t<char>::fast cfast;	//char类型的最快类型
	std::cout << typeindex::type_id<cfast>().pretty_name() << std::endl;

	typedef int_fast_t<int>::fast ifast;	//int类型的最快类型
	std::cout << typeindex::type_id<ifast>().pretty_name() << std::endl;

	typedef int_fast_t<uint16_t>::fast u16fast;	//uint16类型的最快类型
	std::cout << typeindex::type_id<u16fast>().pretty_name() << std::endl;
	return 0;
}
