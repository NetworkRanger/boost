#include <boost/ratio.hpp>
#include <iostream>
using namespace boost;

template<typename R>
using string_out = ratio_string<R, char>;		//使用using别名

int main(){
	std::cout << string_out<kilo>::symbol() << std::endl;		//k
	std::cout << string_out<kilo>::prefix() << std::endl;		//kilo

	std::cout << string_out<nano>::symbol() << std::endl;		//n
	std::cout << string_out<nano>::prefix() << std::endl;		//nano

	std::cout << string_out<ratio<22, 7> >::prefix() << std::endl;		//[22/7]
	return 0;
}
