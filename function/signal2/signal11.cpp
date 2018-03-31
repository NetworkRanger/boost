template<typename Signature>
class sig_ex{
public:
	typedef signal<Signature>	signal_type;
	typedef typename signal_type::slot_type slot_type;

	connection connect(const slot_type &s){	//连接插槽
		return sig.connect(s);
	}

	connection operator+=(const slot_type &s){		//操作符+=重载连接
		return connect(s);
	}

	template<typename ... Args>		//可变参数模版
	typename signal_type::result_type operator()(Args && ... args){
		return sig(std::forward<Args>(args)...);		//完美转发
	}
private:
	signal_type sig;
};

int main(){
	sig_ex<int(int)> sig;

	sig += slots<10>();	//使用类似C#的语法连接插槽
	sig += slots<5>();

	sig(2);		//信号调用
	return 0;
}























