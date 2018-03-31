#include <boost/smart_ptr.hpp>
using namespace boost;

int main(){
	int *arr = new int[100];			//一个整数的动态数组
	scoped_array<int> sa(arr);			//scoped_array对象代理原始动态数组

	std::fill_n(&sa[0], 100, 5);				//可以使用标准库算法赋值数据
	sa[10] = sa[20] + sa[30];			//用起来就像是个普通数组
	return 0;							//这里scoped_array被自动析构，释放动态数组资源
}
