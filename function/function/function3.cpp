class demo_class{
private:
	typedef function<void(int)> func_t;		//function类型定义
	func_t func;		//function对象
	int n;
public:
	demo_class(int i) : n(i){}
	template<typename CallBack>
	void accept(CallBack f){		//存储回调函数
		func = f;
	}
	void run(){
		func(n);
	}
};

void call_back_func(int i){
	std::cout << "call_back_func:";
	std::cout << i*2 << std::endl;
}

int main(){
	demo_class dc(10);
	dc.accept(call_back_func);	//接受回调参数
	dc.run();			//调用回调参数，输出“call_back_func:20"
	return 0;
}
