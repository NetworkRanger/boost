#include <boost/assign.hpp>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <forward_list>

int main(){
	using namespace boost::assign;

	std::vector<int> v;
	push_back(v)(1)(2)(3)(4)(5);								//使用push_back工厂函数

	std::list<std::string> l;
	push_front(l)("cpp")("java")("c#")("python");				//使用push_front工厂函数

	std::forward_list<std::string> fl;							//C++11 的单向链表
	push_front(l)("matrix")("reload");							//使用push_front工厂函数

	std::set<double> s;												
	insert(s)(3.14)(0.618)(1.732);				//使用insert工厂函数

	std::map<int, std::string> m;
	insert(m)(1, "one")(2, "two");				//使用insert工厂函数
	return 0;
}
