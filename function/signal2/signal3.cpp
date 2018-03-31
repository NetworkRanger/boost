#include <boost/signals2.hpp>
using namespace boost::signals2;

int main(){
	signal<int(int)> sig;

	connection c1 = sig.connect(0, slots<10>());
	connection c2 = sig.connect(0, slots<20>());
	connection c3 = sig.connect(1, slots<30>());

	c1.disconnection();		//断开一个连接
	assert(sig.num_slots() == 2);	//sig现在连接两个插槽
	assert(!c1.connected());		//c1不再连接信号
	assert(c2.connected());			//c2仍然连接
	return 0;
}
