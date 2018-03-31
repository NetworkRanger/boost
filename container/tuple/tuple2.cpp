#include <boost/tuple/tuple_io.hpp>
#include <iostream>
#include <string>
#include <tuple>
using namespace boost;

int main(){
	typedef std::tuple<int, double, std::string> my_tuple;
	my_tuple t1(1, 2.0, "string");
	std::cout << t1 << std::endl;

	std::cout << "please input tuple:";
	std::cin >> t1;

	std::cout << t1 << std::endl;
	return 0;
}
