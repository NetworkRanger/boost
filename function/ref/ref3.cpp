class big_class{
private:
	int x;
public:
	big_class() : x(0){}
	void print(){
		std::cout << "big_class" << ++x << std::endl;
	}
};

template<typename T>
void print(T a){
	for(int i=0;i<2;++i){
		unwrap_ref(a).print();		//解包装
	}
}

int main(){
	big_class c;
	auto rw = ref(c);
	c.print();		//输出1

	print(c);		//拷贝传参，输出2，3，内部状态不改变
	print(rw);		//引用传参，输出2，3，内部状态改变
	print(c);		//拷贝传参，输出4，5，内部状态不改变
	c.print();		//输出4
	return 0;
}
