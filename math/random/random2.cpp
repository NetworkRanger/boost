#include <boost/random.hpp>
using namespace boost;

int main(){
	mt19937 rng(time(0));		//使用mt19937

	random::uniform_int_distribution<> ui(0, 255);	//0~255之间的整数
	for(int i=0;i<10;++i){
		std::cout << ui(rng) << ",";
	}
	std::cout << std::endl;

	uniform_01<> u01;		//0~1之间的小数
	for(int i=0;i<10;++i){
		std::cout << u01(rng) << ",";
	}
	std::cout << std::endl;

	//定义一个均值为1,方差为2的正态分布
	normal_distribution<> nd(1, 2);		//正态分布
	int count = 0;
	for(int i=0;i<10000;++i){
		//计算正态分布的统计学概率
		if(abs(nd(rng) -1) <= 2.0){
			++count;
		}
	}
	std::cout << 1.0*count / 1000 << std::endl;
	return 0;
}
