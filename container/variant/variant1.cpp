#include <boost/variant.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	typedef variant<int, double, std::string> var_t;
	var_t v;		//缺省构造，v==0
	assert(v.type() == typeid(int));	//v->int
	assert(v.which() == 0);		//v现在持有第一个类型的元素

	v = "variant demo";		//v->string
	std::cout << *get<std::string>(&v) << std::endl;		//使用get()函数取值

	try{
		std::cout << get<double>(v) << std::endl;
	}catch(bad_get &){
		std::cout << "bad_get" << std::endl;
	}
	return 0;
}
