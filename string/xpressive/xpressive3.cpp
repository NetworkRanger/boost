#include <boost/xpressive/xpressive_dynamic.hpp>
#include <iostream>

int main(){
	using namespace boost::xpressive;

	cregex reg = cregex::compile("\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))", icase);

	cmatch what;	//匹配结果对象
	assert(regex_match("999555197001019999", what, reg));
	for(auto &x : what){
		std::cout << "[" << x << "]";
	}
	std::cout << std::endl;

	std::cout << "date:" << what[1] << what[3] << what[5] << std::endl;

	return 0;
}
