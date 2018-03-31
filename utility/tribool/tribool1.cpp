#include <boost/logic/tribool.hpp>
#include <iostream>
#include <assert.h>
using namespace boost;

int main(){
	tribool tb(true);			//值为ture的tribool
	tribool tb2(!tb);			//值为false

	if(tb){						//tb == true
		std::cout << "true" << std::endl;
	}

	tb2 = indeterminate;		//tb2是不确定状态
	assert(indeterminate(tb2));	//用indeterminate函数检测状态
	std::cout << tb2 << std::endl;

	if(tb2 == indeterminate){	//与indeterminate值比较，无意义
		std::cout << "indeterminate" << std::endl;	//这行语句不会执行
	}
	if(indeterminate(tb2)){		//用indeterminate函数检测状态
		std::cout << "indeterminate" << std::endl; //输出"indeterminate"
	}

	std::cout << (tb2 || true) << std::endl;		//逻辑或运算，输出true
	std::cout << (tb2 || false) << std::endl;		//逻辑与运算，输出false
	return 0;
}
