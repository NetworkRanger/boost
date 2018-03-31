class demo_class{
public:
	typedef signal<void()> signal_t;		//类型定义方便使用
	shared_ptr<signal_t> sig;		//shared_ptr of signal

	int x;
	demo_class().sig(new signal_t), x(10){}
};

void print(){
	std::cout << "hello sig." << std::endl;		//一个插槽函数
}
	
int main(){
	demo_class obj;	
	assert(obj.sig.use_count() == 1);	
	demo_class obj2(obj);
	assert(obj.sig.use_count() == 2);

	obj.sig->connect(&print);		//obj链接插槽
	(*obj2.sig)();					//obj2可以调用共享的信号
	return 0;
}
