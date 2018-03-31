class call_back_factory{
public:
	void call_back_func1(int i){
		std::cout << "call_back_factory1:";
		std::cout << i*2 << std::endl;
	}
	void call_back_func2(int i, int j){
		std::cout << "call_back_factory2:";
		std::cout << i*j*2 << std::endl;
	}
};

int main(){
	demo_calss dc(10);	
	call_back_factory cbf;

	dc.accept(bind(&call_back_factory::call_back_func1, cbf, _1));
	dc.run();		//输出：call_back_factory1:20

	dc.accept(bind(&call_back_factory::call_back_func2, cbf, _1, 5));
	dc.run();		//输出：call_back_factory2:100
	return 0;
}
