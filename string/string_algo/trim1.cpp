#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	format fmt("|%s|\n");
	
	std::string str = "	samus aran	";
	std::cout << fmt % trim_copy(str);			//删除两端空格
	std::cout << fmt % trim_left_copy(str);		//删除左端空格

	trim_right(str);							//原地删除右端的空格
	std::cout << fmt % str;

	std::string str2 = "2015 Happy new Year!!!";
	std::cout << fmt % trim_left_copy_if(str2, is_digit());		//删除左端的数字
	std::cout << fmt % trim_right_copy_if(str2, is_punct());	//删除右端的标点
	std::cout << fmt % trim_copy_if(str2, is_punct() || is_digit() || is_space());	//删除两端的标点，数字和空格
	return 0;
}
