#include <iostream>
#include <memory>
#include <vector>

int main(){
	typedef std::vector<std::shared_ptr<int>> vs;		//一个持有shared_ptr的标准容器类型
	vs v(10);								//声名一个拥有10个元素的容器

	int i=0;
	for(auto pos=v.begin();pos!=v.end();++pos){
		(*pos) = std::make_shared<int>(++i);		//使用工厂函数赋值
		std::cout<< *(*pos) << ", ";				//输出值
	}
	std::cout << std::endl;

	std::shared_ptr<int> p = v[9];
	*p = 100;
	std::cout << *v[9] << std::endl;
	return 0;
}
