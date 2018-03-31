#include <boost/timer.hpp>		//timer的头文件
#include <iostream>
using namespace boost;			//打开boost命名空间

int main(){
	timer t;					//声明一个计时器对象，开始计时

	std::cout << "max timespan:" << t.elapsed_max()/3600 << "h" << std::endl;		//可度量的最大时间，以小时为单位
	std::cout << "min timespan:" << t.elapsed_min() << "s" << std::endl;			//可度量的最小时间，以秒为单位
	std::cout << "now time elapsed:" << t.elapsed() << "s" << std::endl;			//输出已经流逝的时间
	return 0;	
}
