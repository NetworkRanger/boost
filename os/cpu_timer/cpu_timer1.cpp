#include <boost/timer/timer.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace boost::timer;

int main(){
	std::vector<std::string> v(10, "monado");		//一个存储字符串的容器

	cpu_timer t;	//声明同时启动计时器
	assert(!t.is_stopped());		//计时器已经启动

	for(int i=0;i<10000;++i){
		boost::join(v, "-");	//Boost的字符串连接算法
	}

	t.stop();		//暂时计时器
	assert(t.is_stopped());		//计时器已经暂停

	std::cout << "pause for a while..." << std::endl;		//标准流输出
	std::cout << "we can do something..." << std::endl;		//不计入时间

	t.resume();		//恢复计时器运行
	assert(!t.is_stopped());	//计时器已经启动

	BOOST_FOREACH(std::string &x, v){
		x += x;
	}
	std::cout << t.format();		//格式化输出计时器	
	return 0;
}
