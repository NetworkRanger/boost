#include <boost/crc.hpp>
#include <iostream>
using namespace boost;

int main(){
	crc_32_type crc32;		//一个crc对象

	std::cout << std::hex;	//置输出流为hex格式
	std::cout << crc32.checksum() << std::endl;	//无输入数据时也可取crc值

	crc32.process_byte('a');		//计算一个字节
	std::cout << crc32.checksum() << std::endl;

	char szCh[] = "1234567890";		//一个字符数组
	crc32.reset();		//复位crc处理机

	crc32.process_block(szCh, szCh+10);	//使用区间的形式输入数据
	std::cout << crc32.checksum() << std::endl;
	return 0;
}
