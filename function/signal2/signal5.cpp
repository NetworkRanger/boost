#include <boost/signals2.hpp>
using namespace boost::signals2;

int main(){
	signal<int(int)> sig;

	connection c1 = sig.connect(0, slots<10>());
	connection c2 = sig.connect(0, slots<20>());
	assert(sig.num_slots() == 2);		//有两个插槽
	sig(2);		//调用两个插槽

	std::cout << "begin blocking..." << std::endl;
	{
		shared_connection_block block(c1);	//阻塞c1连接
		assert(sig.num_slots() == 2);		//仍然有两个连接
		assert(c1.blocked());				//c1被阻塞
		sig(2);			//只有一个插槽会被调用
	}		//离开作用域，阻塞自动解除

	std::cout << "end blocking..." << std::endl;
	assert(!c1.blocked());
	sig(2);			//可以调用两个插槽
	return 0;
}
