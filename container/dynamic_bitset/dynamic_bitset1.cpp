#include <boost/dynamic_bitset.hpp>
#include <iostream>
using namespace boost;

int main(){
	int n;
	std::cin >> n;
	dynamic_bitset<> db(n);
	db.set();
	for(dynamic_bitset<>::size_type i = db.find_next(1);
		i != dynamic_bitset<>::npos;	//因为dynamic_bitset不是容器
		i = db.find_next(i)){			//所以不能使用for+auto遍历
		for(dynamic_bitset<>::size_type j = db.find_next(i);
			j != dynamic_bitset<>::npos;
			j = db.find_next(j)){
			if(j%i == 0) db[j] = 0;		//被整数，非质数			
		}
	}
	for(dynamic_bitset<>::size_type i = db.find_next(2);
		i != dynamic_bitset<>::npos;
		i = db.find_next(i)){
		std::cout << i<< ", ";			//输出质数
	}
	return 0;
}
