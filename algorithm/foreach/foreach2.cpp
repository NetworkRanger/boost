#include <boost/foreach.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <map>

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

int main(){
	int ar[] = {1, 2, 3, 4, 5};
	foreach(auto &x, ar){
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::map<int, std::string> m = { {1, "111"}, {2, "222"}, {3, "333"} };
	foreach(auto &x, m){
		std::cout << x.first << x.second << std::endl;
	}

	std::vector<std::vector<int> > v = { {1,2}, {3, 4} };
	foreach(std::vector<int> &row, v){
		reverse_foreach(auto &z, row){
			std::cout << z << ",";
		}
		std::cout << std::endl;
	}
		
	return 0;
}
