#include <boost/smart_ptr.hpp>
#include <iostream>
using namespace boost;

struct posix_file{
	posix_file(const char *file_name){
		std::cout << "open file:" << file_name << std::endl;
	}
	~posix_file(){
		std::cout<<"close file:" << std::endl;
	}
};

int main(){
	//文件类的scoped_ptr,将在离开作用域时自动析构，从而关闭文件释放资源
	scoped_ptr<posix_file> fp(new posix_file("/tmp/a.txt"));

	scoped_ptr<int> p(new int);				//一个int指针的scoped_ptr

	if(p){									//在bool语境中测试指针是否有效
		*p = 100;							//可以像普通指针一样使用解引用操作符*
		std::cout << *p << std::endl;
	}
	p.reset();								//置空scoped_ptr，仅仅是演示

	assert(p == 0);							//与0比较，p不支持有任何指针
	if(!p){
		std::cout << "scoped_ptr == nullptr" << std::endl;
	}
	return 0;
}
