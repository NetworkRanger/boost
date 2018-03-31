#include <boost/xpressive/xpressive_dynamic.hpp>

int main(){
	using namespace boost::xpressive;

	cregex reg = cregex::compile(R"---(\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d))---", icase);

	assert(regex_match("999555197001019999", reg));
	assert(regex_match("99955519700101999X", reg));
	assert(regex_match("99955519700101999x", reg));

	assert(!regex_match("99955520100101999Z", reg));
	assert(!regex_match("99955530100101999X", reg));
	assert(!regex_match("999555201099019998", reg));
	assert(!regex_match("999555201012419991", reg));
	return 0;
}
