#include <boost/array.hpp>
#include <iostream>
#include <algorithm>
using namespace boost;

int main(){
	array<int, 10> ar;		//一个大小为10的int数组

	ar[0]  = 1;			//使用operator[[
	ar.back() = 10;		//back()访问最后一个元素
	assert(ar[ar.max_size()-1] == 10);

	ar.assign(77);		//数组所有元素赋值777
	for(auto x : ar){
		std::cout << x << ",";
	}

	int *p = ar.c_array();		//获得原始数组指针
	*(p+5) = 253;				//指针算术运算
	std::cout << ar[5] << std::endl;

	ar.at(8) = 666;		//使用at函数访问元素
	std::sort(ar.begin(), ar.end());		//可以使用标准算法排序
	return 0;
}
