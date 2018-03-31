#include <boost/xpressive/xpressive_dynamic.hpp>

int main(){
	using namespace boost::xpressive;		//打开命名空间

	cregex reg = cregex::compile("a.c");	//C字符串正则表达式对象

	assert(regex_match("abc", reg));		//匹配
	assert(regex_match("a+c", reg));		//匹配
	assert(!regex_match("ac", reg));		//不匹配
	assert(!regex_match("abd", reg));		//不匹配
	return 0;
}
