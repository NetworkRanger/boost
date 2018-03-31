#include <boost/integer_traits.hpp>
#include <iostream>
using namespace boost;

int main(){
	std::cout << integer_traits<int>::const_max << std::endl;
	std::cout << integer_traits<bool>::const_min << std::endl;
	std::cout << integer_traits<long>::is_signed << std::endl;
	return 0;
}
