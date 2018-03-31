#include <boost/xpressive/xpressive_dynamic.hpp>
#include <iostream>
#include <string>

int main(){
	using namespace boost::xpressive;
	std::string str("readme.txt");

	sregex reg1 = sregex::compile("(.*)(me)");
	sregex reg2 = sregex::compile("(t)(.)(t)");

	std::cout << regex_replace(str, reg1, "manual") << std::endl;
	std::cout << regex_replace(str, reg1, "$1you") << std::endl;
	std::cout << regex_replace(str, reg1, "$&$&") << std::endl;
	std::cout << regex_replace(str, reg2, "$1N$3") << std::endl;
	return 0;
}
