#include <boost/optional.hpp>
#include <string>
#include <vector>
#include <iostream>
using namespace boost;

int main(){
	optional<int> op0;				//一个未初始化的optional对象
	optional<int> op1(none);		//同上，使用none赋予未初始化值

	assert(!op0);					//bool测试
	assert(op0 == op1);				//比较两个optional对象

	assert(op1.value_or(253) == 253);			//获取缺省值
	std::cout << op1.value_or_eval([](){		//使用函数对象
		return 874;								//lambda表达式定义函数对象
	}) << std::endl;

	optional<std::string> ops("test");				//初始化为字符串test
	std::cout << *ops << std::endl;				//用解引用操作符获取值

	ops.emplace("monado", 3);					//就地创建一个字符串，没有拷贝代价
	assert(*ops == "mon");						//只使用了前个字符

	std::vector<int> v(10);						
	optional<std::vector<int> &> opv(v);		//容纳一个容器的引用
	assert(opv);								//bool转型

	opv->push_back(5);							//使用箭头操作符操纵容器
	assert(opv->size() == 1);

	opv = none;									//置为未初始化状态
	assert(!opv);								//此时为无效值
	return 0;
}
