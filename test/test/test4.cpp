#include <boost/test/execution_monitor.hpp>
#include <iostream>
using namespace boost;

int f(){		//一个简单的测试函数，必须是无参返回值为int
	std::cout << "f execute." << std::endl;
	throw "a error accoured";		//抛出一个未捕获的异常
	return 10;
}

int main(){
	execution_monitor em;		//声明一个监视器对象
	try{
		em.execute(f);		//监控执行f
	}catch(execution_exception &e){
		std::cout << "execution_exception" << std::endl;
		std::cout << e.what().begin() << std::endl;		//抛出异常信息
	}
		
	return 0;
}
	
