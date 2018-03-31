#include <assert.h>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	std::string str("Power Bomb");

	assert(iends_with(str, "bomb"));		//大小写无关检测后缀
	assert(!ends_with(str, "bomb"));		//大小写敏感检测后缀

	assert(starts_with(str, "Pow"));		//检测前缀

	assert(contains(str, "er"));			//测试包含关系

	std::string str2 = to_lower_copy(str);		//转换小写
	assert(iequals(str, str2));				//大小写无关判断相等

	std::string str3("power suit");
	assert(ilexicographical_compare(str, str3));		//大小写无关比较

	assert(all(str2.substr(0, 5), is_lower()));			//检测字串均小写
	return 0;
}
