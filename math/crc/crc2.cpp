#include <boost/crc.hpp>
#include <iostream>
#include <algorithm>
#include <string>
using namespace boost;

int main(){
	crc_32_type crc32;		//一个crc对象

	std::cout << std::hex;	//置输出流为hex格式
	std::cout << crc32() << std::endl;	//无输入数据时也可取crc值

	std::string str = "1234567890";		//一个字符数组
	crc32.reset();		//复位crc处理机

	//把crc对象作为函数对象传递给for_each算法处理字符串
	std::cout << std::for_each(str.begin(), str.end(), crc32)() << std::endl;
	std::cout << crc32() << std::endl;
	return 0;
}
