#include <boost/format.hpp>
#include <iostream>
using namespace boost;

int main(){
	std::cout << format("%s:%d+%d=%d\n") % "sum" % 1 % 2 % (1+2);

	format fmt("(%1% + %2%) * %2% = %3%\n");
	fmt % 2 % 5;
	fmt % ((2+5)*5);
	std::cout << fmt.str();
	return 0;
}
