#include <boost/assign.hpp>
#include <boost/algorithm/minmax_element.hpp>
#include <iostream>
#include <vector>
using namespace boost;

int main(){
	std::vector<int> v = {3, 5, 2, 2, 10, 9, 10, 8};		//初始化测试数据

	decltype(v.begin()) pos;	//保存查找到的迭代器位置
	pos = first_min_element(v.begin(), v.end());	//找到第一个最小值
	assert(pos - v.begin() == 2);	//v[2]

	pos = last_min_element(v.begin(), v.end());	//最后一个最小值
	assert(pos - v.begin() == 3);	//v[3]

	auto x = first_min_last_max_element(v.begin() ,v.end());	//第一个最小值和最后一个最后值

	assert(x.first - v.begin() == 2 && x.second - v.begin() == 6);
	return 0;
}
