#include <boost/assign.hpp>
#include <string>
#include <vector>
#include <set>
#include <map>

int main(){
	using namespace boost::assign;			//很重要，启用assign库的功能

	std::vector<int> v;							//标准向量容器
	v += 1, 2, 3, 4, 5, 6*6;				//使用operator+=和，填充数据

	std::set<std::string> s;							//标准集合容器
	s += "cpp", "java", "c#", "python";

	std::map<int, std::string> m;						//标准映射容器
	m += std::make_pair(1, "one"), std::make_pair(2, "two");
	return 0;
}
