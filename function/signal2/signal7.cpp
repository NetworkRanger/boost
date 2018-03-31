int main(){
	typedef signal<int(int)> signal_t;
	typedef signal_t::slot_type slot_t;
	signal_t sig;

	//声明两个shared_ptr
	auto p1 = boost::make_shared<slots<10>>();
	auto p2 = boost::make_shared<slots<20>>();

	function<int(int)> func = ref(*p1);		//function存储引用

	sig.connect(slot_t(func).track(p1));	//直接跟踪function

	//使用bind语法，直接绑定
	sig.connect(slot_t(&slots<20>::operator(), p2.get(), _1).track(p2));

	p1.reset();			//销毁两个指针对象
	p2.reset();			
	assert(sig.num_slots() == 0);		//此时已经自动断开了所有连接
	sig(1);				//不发生任何插槽调用
	return 0;
}
