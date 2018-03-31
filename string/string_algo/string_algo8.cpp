#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/utility/string_ref.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace boost;

int main(){
	using namespace boost::assign;
	std::vector<std::string> v = list_of("Samus")("Link")("Zelda")("Mario");

	std::cout << join(v, "+") << std::endl; //简单合并
	
	std::cout << join_if(v, "**", [](string_ref s){		//带谓词的合并
		return contains(s, "a");
	});

	return 0;
}
