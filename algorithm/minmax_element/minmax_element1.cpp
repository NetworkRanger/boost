#include <boost/algorithm/minmax_element.hpp>
#include <vector>
#include <iostream>
using namespace boost;

int main(){
	std::vector<int> v = {633, 90, 67, 83, 2, 100};

	auto x = minmax_element(v.begin(), v.end());
	std::cout << "min:	" << *x.first << std::endl;
	std::cout << "max:	" << *x.second << std::endl;
	return 0;
}
