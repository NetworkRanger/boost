template<int N>
struct slots{
	int operator()(const connection &conn, int x){		//检查连接状态
		std::cout << "conn=" << conn.connected() << std::endl;
		return x*N;
	}
};
	
int main(){
	typedef signal<int(int)> signal_t;
	typedef signal_t::extended_slot_type slot_t;
	signal_t sig;

	//_1是connection对象，_2是插槽实际使用的参数
	sig.connect_extended(slot_t(&slots<10>::operator(), slots<10>(), _1, _2));
	sig.connect_extended(slot_t(&slots<20>::operator(), slots<20>(), _1, _2));
	sig(5);	//整数5将作为_2的实际参数传给插槽
	return 0;
}
