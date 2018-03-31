#include <boost/tuple/tuple.hpp>
#include <iostream>
#include <tuple>
#include <string>
using namespace boost;

typedef std::tuple<int, double, std::string> my_tuple;		//3-tuple定义

my_tuple func(){
	return std::make_tuple(1, 2.0, "string");
}

int main(){
	int i;
	double d;
	std::string s;		//3个普通变量
	tie(i, d, s) = func();		//使用tie()接受函数返回的tuple
	std::cout << i;
	return 0;
}
