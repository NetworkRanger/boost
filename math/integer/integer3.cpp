#include <boost/cstdint.hpp>
#include <limits>
#include <iostream>
using namespace boost;

int main(){
	uint8_t u8;		//一个简单的8位无符号整数，相当于unsigned char
	int_fast16_t i16;		//最快的有符号16整数
	int_least32_t i32;		//至少有32位的有符号整数
	uintmax_t um;			//编译器支持的最大无符号整数类型

	u8 = 255;
	i16 = 32000;
	i32 = i16;
	um = u8 + i16 + i32;

	//输出各整数类型的大小和值
	std::cout << "u8 :" << sizeof(u8) << " v = " << (short)u8 << std::endl;
	std::cout << "i16 :" << sizeof(i16) << " v = " << i16 << std::endl;
	std::cout << "i32 :" << sizeof(i32) << " v = " << i32 << std::endl;
	std::cout << "um :" << sizeof(um) << " v = " << um << std::endl;

	//输出各整数类型的极值
	std::cout << (short)std::numeric_limits<int8_t>::max() << std::endl;
	std::cout << std::numeric_limits<uint_least16_t>::max() << std::endl;
	std::cout << std::numeric_limits<int_fast32_t>::max() << std::endl;
	std::cout << std::numeric_limits<intmax_t>::min() << std::endl;
	return 0;
}
