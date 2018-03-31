#include <boost/assign.hpp>

int main(){
	using namespace boost::assign;

	std::vector<int> v = list_of(1)(2)(3)(4)(5);
	//v = [1, 2, 3, 4, 5]
	
	std::deque<std::string> d = (list_of("power")("bomb"), "phazon", "suit");	//注意括号与逗号的使用
	//d = [power bomb phazon suit]

	std::set<int> s = (list_of(10), 20, 30, 40, 50);						//注意括号与逗号的使用
	//s = {10 20 30 40 50}
	
	std::map<int, std::string> m = list_of(std::make_pair(1, "one"))(std::make_pair(2, "two"));
	//m = [(1, "one") (2, "two")]

	return 0;
}
