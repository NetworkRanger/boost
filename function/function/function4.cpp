class call_back_obj{
private:
	int x;	//内部状态
public:
	call_back_obj(int i) : x(i){}
	void operator()(int i){
		std::cout << "call_back_obj:";
		std::cout << i*x << std::endl;
	}
};

int main(){
	demo_class dc(10);	
	call_back_obj cbo(2);	
	dc.accept(ref(cbo));		//使用ref库
	dc.run();		//输出：call_back_obj:20
	dc.run();		//输出：call_back_obj:30
	return 0;
}
