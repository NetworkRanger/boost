#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <vector>
using namespace boost::uuids;

int main(){
	uuid u;		//声明一个uuid对象
	assert(uuid::static_size() == 16);		//uuid的长度总为16

	std::vector<unsigned char> v(16, 7);			//一个vector对象
	std::copy(v.begin(), v.end(), u.begin());		//使用标准复制算法
	assert(u.data[0] == u.data[1] && u.data[15] == 7);

	//流输出:07070707-0707-0707-0707-07070707
	std::cout << u << std::endl;
	std::fill_n(u.data + 10, 6, 8);			//标准算法fill_n直接操纵数组

	//流输出:07070707-0707-0707-0707-08080808
	std::cout << u << std::endl;
	return 0;
}
