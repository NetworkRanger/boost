#include <boost/assign.hpp>
#include <map>
#include <string>

int main(){
	using namespace boost::assign;

	std::map<int, int> m1 = map_list_of(1, 2)(3, 4)(5, 6);
	//m1 = [(1, 2) ( 3, 4) (5, 6)]
	
	std::map<int, std::string> m2 = map_list_of(1, "one")(2, "two");
	//m2 = [(1, "one")(2, "two")]
	return 0;
}
