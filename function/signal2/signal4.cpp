#include <boost/signals2.hpp>
using namespace boost::signals2;

int main(){
	signal<int(int)> sig;

	sig.connect(0, slots<10>());
	assert(sig.num_slots() == 1);
	{
		scoped_connection sc = sig.connect(0, slots<20>());
		assert(sig.num_slots() == 2);
	}	//离开局部作用域，临时连接自动断开

	assert(sig.num_slots() == 1);
	return 0;
}
