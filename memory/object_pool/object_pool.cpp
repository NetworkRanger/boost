#include <boost/pool/object_pool.hpp>
#include <string>
#include <iostream>
using namespace boost;

struct demo_class{
public:
	int a, b, c;
	demo_class(int x = 1, int y = 2, int z = 3) : a(x), b(y), c(z){}
};

int main(){
	object_pool<demo_class> pl;			//对象内存池

	auto p = pl.malloc();				//分配一个原始内存块
	assert(pl.is_from(p));				

	//p指向的内存未经过初始化
	assert(p->a != 1 || p->b != 2 || p->c != 3);

	p = pl.construct(7, 8, 9);			//构造一个对象，可以传递参数
	assert(p->a == 7);					

	object_pool<std::string> pls;			//定义一个分配string对象的内存池
	for(int i=0;i<10;++i){
		std::string *ps = pls.construct("hello object_pool");
		std::cout << *ps << std::endl;
	}
	return 0;
}
