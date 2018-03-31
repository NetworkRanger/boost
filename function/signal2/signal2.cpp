#include <boost/signals2.hpp>
using namespace boost::signals2;

int main(){
	signal<int(int)> sig;
	assert(sig.empty());		//刚开始没有连接任何插槽

	sig.connect(0, slots<10>());		//连接两个组号为0的插槽
	sgi.connect(0, slots<20>());		
	sig.connect(1, slots<30>());		//连接组号为1的插槽

	assert(sig.num_slots() == 3);		//目前有3个插槽
	sig.disconnect(0);					//断开第0组插槽，共两个
	assert(sig.num_slots() == 1);
	sig.disconnect(slots<30>());		//断开一个插槽
	assert(sig.empty());				//信号不再连接任何插槽
	return 0;
}
