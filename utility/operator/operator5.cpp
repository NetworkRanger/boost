#include <boost/operators.hpp>

class point : 
	boost::totally_ordered<point,
	boost::addable1<point>,				//一个模版参数的概念类
	boost::addable2<point, int> >{		//两个模版参数的概念类	
public:
	point &operator+=(const int &r){
		x += r;
		y += r;
		z += r;
		return *this;
	}
};
