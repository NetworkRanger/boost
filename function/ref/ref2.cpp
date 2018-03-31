#include <boost/ref.hpp>
using namespace boost;

int main(){
	int x = 10;
	reference_wrapper<int> rw(x);	//包装int类型的引用
	assert(x == rw);				//隐式转换为int类型
	(int &)rw = 100;				//显示转换为int &类型
	assert(x == 100);

	reference_wrapper<int> rw2(rw);	//拷贝构造
	assert(rw2.get() == 100);

	std::string str;
	reference_wrapper<std::string> rws(str);		//包装字符串的引用
	*rws.get_pointer() = "test reference_wrapper";	//指针操作
	std::cout << rws.get().size() << std::endl;
	return 0;
}
