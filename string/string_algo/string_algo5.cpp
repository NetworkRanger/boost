#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	format fmt("|%s|. pos = %d\n");

	std::string str = "Long long ago, there was a king.";

	iterator_range<std::string::iterator> rge;		//迭代器区间

	rge = find_first(str, "long");				//找第一次出现
	std::cout << fmt % rge % (rge.begin() - str.begin());

	rge = ifind_first(str, "long");				//大小写无关找第一次出现
	std::cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_nth(str, "ng", 2);				//找出第三次出现
	std::cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_head(str, 4);					//取出前4个字符
	std::cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_tail(str, 5);					//取末尾5个字符
	std::cout << fmt % rge % (rge.begin() - str.begin());

	rge = find_first(str, "samus");				//找不到
	assert(rge.empty() && !rge);
	return 0;
}
