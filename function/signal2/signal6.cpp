int main(){
	signal<int(int)> sig;

	sig.connect(slots<10>());	//正常连接

	auto p = new slots<20>;		//创建一个指针对象
	sig.connect(ref(*p));		//用ref包装,连接到引用

	delete p;		//指针被销毁
	sig(1);			//信号调用将发生未定义行为
	return 0;
}
