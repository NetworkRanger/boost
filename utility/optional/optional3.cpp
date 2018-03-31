#include <boost/optional.hpp>
using namespace boost;

int main(){
	auto x = make_optional(5);			//使用auto关键字自动推导类型
	assert(*x == 5);

	auto y = make_optional<double>((*x > 10), 1.0);		//模板参数明确类型
	assert(!y);
	return 0;
}
