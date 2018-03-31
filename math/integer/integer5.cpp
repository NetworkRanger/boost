#include <boost/integer.hpp>
#include <boost/type_index.hpp>
#include <boost/format.hpp>
#include <iostream>
using namespace boost;

template<typename T>
std::string type_name(){	//简化类型名的输出
	return typeindex::type_id<T>().pretty_name();
}

int main(){
	format fmt("type:%s,size=%dbit\n");		

	typedef uint_t<15>::fast u15;		//可容纳15位的无符号最快整数
	std::cout << fmt % type_name<u15>() % (sizeof(u15) * 8);

	typedef int_max_value_t<32700>::fast i32700;		//可处理32700的最快整数
	std::cout << fmt % type_name<i32700>() % (sizeof(i32700) * 8);

	typedef int_min_value_t<-33000>::fast i33000;	//可处理-33000的最快整数
	std::cout << fmt % type_name<i33000>() % (sizeof(33000) * 8);

	typedef uint_value_t<33000>::fast u33000;		//可处理33000的最快无符号整数
	std::cout << fmt % type_name<u33000>() % (sizeof(u33000) * 8);
	return 0;
}
