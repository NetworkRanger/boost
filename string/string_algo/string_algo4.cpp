#include <boost/algorithm/string.hpp>
#include <boost/utility/string_ref.hpp>
#include <string>
#include <assert.h>
using namespace boost;

int main(){
	std::string str1("Samus"), str2("samus");

	assert(!is_equal()(str1, str2));
	assert(is_equal()(str1, str2));

	assert(!is_equal()(str1, string_ref(str2)));		//使用string_ref
	return 0;
}
