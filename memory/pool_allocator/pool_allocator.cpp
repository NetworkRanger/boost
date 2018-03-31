#include <boost/pool/pool_alloc.hpp>
#include <vector>
#include <iostream>
using namespace boost;

int main(){
	std::vector<int, pool_allocator<int>> v;			//pool_allocator代替默认的内存分配器

	v.push_back(10);							//vector将使用新的分配器良好工作
	std::cout<<v.size();
	return 0;
}
