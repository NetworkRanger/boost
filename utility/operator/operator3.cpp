#include <boost/opeators.hpp>

class point : 
	totally_ordered<point,		//倒序比较运算
	additive<point> >{			//可贺减运算
public:
	friend bool operator<(const point &l, const point &r){}
	friend bool operator==(const point &l, const point &r){}

	point &operator+=(const point &r){	//支持addable概念
		x += r.x;
		y += r.y;
		z += r.z;
		return *this;
	}

	point &operator-=(const point &r)	//支持subtractable概念
		x -= r.x;
		y -= r.y;
		z -= r.z;
		return *this;
	}
}

