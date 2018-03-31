#include <boost/chrono.hpp>
#include <iostream>
using namespace boost::chrono;

template<typename T>
using clock_desc = clock_string<T, char>;	//定义模版别名

int main(){
	std::cout << clock_desc<system_clock>::name() << std::endl;
	std::cout << clock_desc<system_clock>::since() << std::endl;

	std::cout << clock_desc<system_clock>::name() << std::endl;
	std::cout << clock_desc<steady_clock>::since() << std::endl;

	std::cout << clock_desc<process_real_cpu_clock>::name() << std::endl;
	std::cout << clock_desc<process_real_cpu_clock>::since() << std::endl;
	return 0;
}
