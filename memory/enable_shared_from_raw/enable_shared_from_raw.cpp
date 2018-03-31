#include <boost/smart_ptr/enable_shared_from_raw.hpp>
#include <iostream>

class raw_shared : public boost::enable_shared_from_raw{
public:
	raw_shared(){
		std::cout << "raw_shared ctor" << std::endl;
	}
	~raw_shared(){
		std::cout << "raw_shared dtor" << std::endl;
	}
};

int main(){
	raw_shared x;			//一个普通对象
	assert(!weak_from_raw(&x).use_count());		//此时无引用，注意要用&取地址

	auto px = shared_from_raw(&x);				//引用计数为2！
	assert(px.use_count() == 2);				//对象自动删除
	return 0;
}
