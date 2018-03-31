#include <ctime>
#include <boost/random.hpp>
#include <iostream>
#include <vector>
using namespace boost;

int main(){
	mt19937 rng(time(0));		//以时间为种子创建一个随机数发生器

	std::cout << mt19937::min() << "<->" << mt19937::max() << std::endl;	//显示0<->429496725

	for(int i=0;i<100;++i){
		std::cout << rng() << ",";		//使用operator()产生随机数
	}
	rng.discard(5);	//丢弃5个随机数

	std::vector<int> vec(10);		//一个标准容器
	rng.generate(vec.begin(), vec.end());		//调用generate()填充容器
	return 0;
}
