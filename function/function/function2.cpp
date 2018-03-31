int main(){
	std::vector<int> v = {1, 3, 5, 7, 9};

	summary<int> s;		//有状态的函数对象
	function<void(int, const &)> func(ref(s));		//function包装引用

	std::for_each(v.begin(), v.end(), func);		//使用标准库算法
	std::cout << s.sum() << std::endl;
	return 0;
}
