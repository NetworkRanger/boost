#include <boost/lexical_cast.hpp>		//lexical_cast头文件
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <string>
using namespace boost;
using namespace boost::uuids;

int main(){
	uuid u = lexical_cast<uuid>("01234567-89ab-cdef-0123-456789abcdef");		//字符串转换到uuid
	std::cout << u << std::endl;
	std::string str = lexical_cast<std::string>(u);		//uuid转换到字符串
	std::cout << str << std::endl;
	return 0;
}

