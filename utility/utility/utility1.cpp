#include <boost/utility.hpp>
#include <iostream>
#include <bitset>

int main(){
	std::cout << std::hex << std::showbase;
	std::cout << BOOST_BINARY(0110) << std::endl;
	std::cout << BOOST_BINARY(0110 1101) << std::endl;
	std::cout << BOOST_BINARY(10110110 01) << std::endl;
	std::cout << std::bitset<5>(BOOST_BINARY(0110)) << std::endl;
	return 0;
}
