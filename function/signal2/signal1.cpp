#include <boost/signals2.hpp>
using namespace boost::singals2;

void slot1(){
	std::cout << "slot1 called" << std::endl;
	std::cout << "slot2 called" << std::end;
}

signal<void()> sig;		//指定插槽类型void()，其他模版参数使用默认值

int main(){
	signal<void()> sig;		//一个信号对象

	sig.connect(&slots1);		//连接插槽1
	sig.connect(&slots2);		//连接插槽2
	sig();				//调用operator()，产生信号（事件），触发插槽调用
	return 0;
}
