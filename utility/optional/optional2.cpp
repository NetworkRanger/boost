#include <boost/optional.hpp>
#include <iostream>
using namespace boost;

optional<double> calc(int x){		//计算层数
	return optional<double>(x != 0, 1.0 / x);		//条件构造函数
}

optional<double> sqrt_op(double x){			//计算实数的平方根
	return optional<double>(x >= 0, sqrt(x));
}

int main(){
	optional<double> d = calc(10);

	if(d){								//bool语境测试optional的有效性
		std::cout << *d << std::endl;
	}

	d = sqrt_op(-10);
	if(!d){
		std::cout << "no result" << std::endl;			//使用重载的逻辑非操作符
	}
	return 0;
}
