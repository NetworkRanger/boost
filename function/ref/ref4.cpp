#include <functional>

struct square{
	typedef void result_type;
	void operator()(int &x){
		x = x*x;
	}
}

int main(){
	typedef double (*pfunc)(double);
	pfunc pf = sqrt;
	std::cout << std::ref(pf)(5.0);		//包装函数指针

	square sq;
	int x = 5;
	ref(sq)(x);				//包装函数对象
	std::cout << x;

	std::vector<int> v = {1, 2, 3, 4, 5};
	for_each(v.begin(), v.end(), std::ref(sq));
	return 0;
}
