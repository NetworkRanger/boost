#include <boost/uuid/sha1.hpp>
#include <iostream>
#include <string.h>
using namespace boost::uuids::detail;

int main(){
	sha1 sha;			//sha1对象

	char *szMsg = "a short message";			//用于摘要的消息
	sha.process_byte(0x10);						//处理一个字节
	sha.process_bytes(szMsg, strlen(szMsg));	//处理多个字节
	sha.process_block(szMsg, szMsg+strlen(szMsg));

	unsigned int digest[5];					//摘要的返回值
	sha.get_digest(digest);						//获得摘要
	for(int i=0;i<5;++i){
		std::cout << std::hex << digest[i];			//16进制输出
	}
	return 0;
}
