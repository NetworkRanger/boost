#define BOOST_SYSTEM_NO_DEPRECATED			//避免连接boost.system库
#include <boost/pool/pool.hpp>
using namespace boost;

int main(){
	pool<> p1(sizeof(int));			//一个可分配int的内存池

	int *p = static_cast<int *>(p1.malloc());		//必须把void *转换成需要的类型
	assert(p1.is_from(p));	

	p1.free(p);									//释放内存池分配的内存块
	for(int i=0;i<100;++i){
		p1.ordered_malloc(10);					//连续分配大量的内存
	}
	return 0;
}
