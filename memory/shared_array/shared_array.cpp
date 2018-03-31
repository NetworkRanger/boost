#include <boost/smart_ptr.hpp>
using namespace boost;

int main(){
	int *p = new int[100];			//一个动态数组

	shared_array<int> sa(p);		//shared_array代理动态数组
	assert(sa.unique());			//唯一持有指针

	shared_array<int> sa2 = sa;		//共享数组，引用计数数组
	assert(sa2.use_count() == 2);	//引用计数增加

	sa[0] = 10;						//可以使用operator[]访问元素
	assert(sa2[0] == 10);			//离开作用域，自动删除动态数组
	return 0;
}
