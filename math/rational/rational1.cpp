#include <boost/rational.hpp>
using namespace boost;

int main(){
	rational<int> a(3),b(65534),c(22,7);		//三个有理数

	b += a;
	c -= a;
	if(c >= 0){
		c = c*b;
		++a;
	}
	assert(a == 4);
	return 0;
}
