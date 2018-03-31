#include <boost/swap.hpp>
#include <iostream>

namespace std{
	template<>
	void swap(point &x, point &y){
		x.swap(y);					//模版特化swap函数
	}
}

int main(){
	point a(1, 2, 3), b(4, 5, 6);

	std::cout << "std::swap" << std::endl;
	std::swap(a, b);
	std::cout << "boost::swap" << std::endl;
	boost::swap(a, b);				//调用boost::swap
	return 0;
}
