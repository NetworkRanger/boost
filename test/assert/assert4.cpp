#include <boost/static_assert.hpp>
#include <iostream>

template<typename T>
T my_min(T a, T b){
	BOOST_STATIC_ASSERT(sizeof(T) < sizeof(int));	//静态断言
	return a < b ? a : b;
}

int main(){
	std::cout << my_min((short)1, (short)3);		//OK
	std::cout << my_min(1L, 3L);					//编译期错误
	return 0;
}
