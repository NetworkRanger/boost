#include <boost/operators.hpp
class point : boost::less_than_comparable<point>,		//使用多重继承
			  boost::equality_comparable<point>{		//新增相等关系
public:
	friend bool operator<(const point &l, const point &r){
		return (l.x*l.x+l.y*l.y+l.z*l.z < r.x+r.x+r.y*r.y+r.z*r.z);
	}
	friend bool operator==(const point &l, const point &r){
		return r.x == l.x && r.y == l.y && r.z == l.z;
	}
};


