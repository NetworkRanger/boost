#include <boost/function.hpp>
using namespace boost;

int f(int a, int b){
	return a+b;
}

int main(){
	function<int(int, int)> func;	//无参构造一个function对象
	assert(!func);		//此时function不持有任何对象

	func = f;	//func存储函数f
	assert(func.containts(&f));		//验证已经存储函数f

	if(func){
		std::cout << func(10, 20);		//调用function的operator()
	}

	func = 0;		//function清空，相关于clear()
	assert(func.empty());
	return 0;
}
