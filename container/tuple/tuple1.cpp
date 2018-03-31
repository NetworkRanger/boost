#include <boost/tuple/tuple_comparison.hpp>
#include <string>
#include <tuple>
#include <assert.h>
using namespace boost;

int main(){
	typedef std::tuple<int, double, std::string> my_tuple;	//3-tuple

	my_tuple t1 = std::make_tuple(1, 100.0, std::string("abc"));
	my_tuple t2 = std::make_tuple(1, 200.0, std::string("def"));
	assert(t1 < t2);

	my_tuple t3(t2);
	assert(t2 == t3);
	return 0;
}
