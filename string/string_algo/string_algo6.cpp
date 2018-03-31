#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace boost;

int main(){
	std::string str = "Samus beat the monster.\n";

	std::cout << replace_first_copy(str, "Samus", "samus");

	replace_last(str, "beat", "kill");
	std::cout << str;

	replace_tail(str, 9, "ridely.\n");
	std::cout << str;

	std::cout << ierase_all_copy(str, "samus");
	std::cout << replace_nth_copy(str, "l", 1, "L");
	std::cout << erase_tail_copy(str, 8);
	return 0;
}
