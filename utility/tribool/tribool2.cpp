#include <boost/logic/tribool_io.hpp>
#include <iostream>
using namespace boost;

int main(){
	tribool tb1(true), tb2(false), tb3(indeterminate);
	
	std::cout << tb1 << ","		//输出0
		 << tb2 << ","		//输出1
		 << tb3 << std::endl;	//输出2
	return 0;
}
