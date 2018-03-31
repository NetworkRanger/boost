#include <boost/xpressive/xpressive_dynamic.hpp>
#include <iostream>

int main(){
	using namespace boost::xpressive;
	char str[] = "there is a POWER-suit item";
	cregex reg = cregex::compile("(power)-(.{4})", icase);

	assert(regex_search(str, reg)); 	//可搜索到字符串

	cmatch what;
	regex_search(str, what, reg);	//保存搜索结果
	assert(what.size() == 3);		//共3个子表达式

	std::cout << what[1] << what[2] << std::endl;
	assert(!regex_search("error message", reg));
	return 0;
}
