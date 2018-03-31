#include <boost/format.hpp>
#include <iostream>
#include <string>
#include <iomanip>
using namespace boost;
using boost::io::group;

int main(){
	//声明format对象，有三个输入参数，五个格式化选项
	format fmt("%1% %2% %3% %2% %1% \n");

	fmt.bind_arg(2, 10);			//将第二个输入参数固定为数字10
	std::cout << fmt % 1 % 3;		//输入其余两个参数

	fmt.clear();					//清空缓存，但绑定的参数不变
	
	//在%操作符中使用group(),指定输入/输出流操作符第一个参数显示为八进制
	std::cout << fmt % group(std::showbase, std::oct, 111) % 333;

	fmt.clear_binds();				//清除所有绑定参数

	//设置第一个格式化项，十六进制，宽度为8，右对齐，不足位用*填充
	fmt.modify_item(1, group(std::hex, std::right, std::showbase, std::setw(8), std::setfill('*')));
	std::cout << fmt % 49 % 20 % 1000;
	return 0;
}
