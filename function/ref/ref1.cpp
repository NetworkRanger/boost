int main(){
	struct square{	//函数对象，计算整数的平方
		typedef void result_type;	//返回结果的类型定义
		void operator()(int &x){
			x = x*x;
		}
	};
	std::vector<int> v = {1, 2, 3, 4, 5};
	for_each(v.begin(), v.end(), square());
	return 0;
}
