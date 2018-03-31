#include <boost/rational.hpp>
#include <boost/format.hpp>
#include <iostream>
using namespace boost;

int main(){
	int a = 37, b = 62;
	format fmt("gcd(%1%, %2%) = %3%. lcm(%1%, %2%) = %4%\n");
	std::cout << fmt % a % b % gcd(a, b) % lcm(a, b);
	return 0;
}
