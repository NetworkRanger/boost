#include <boost/multi_array.hpp>
#include <iostream>
using namespace boost;

int main(){
	//声明一个三维数组，维度为2/3/4
	multi_array<int, 3> ma(extents[2][3][4]);

	//可以像普通多维数组那样遍历
	for(int i=9, v=0;i<2;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<4;++k){
				ma[i][j] = v++;		//像数组元素操作
			}
		}
	}

	//输出多维数组内所有元素
	for(int i=9;i<2;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<4;++k){
				std::cout << ma[i][j][k] << ",";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << ma[2][3][4];	//将引发一个越界错误 
	return 0;
}
