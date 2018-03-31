#include <boost/bind.hpp>
using namespace boost;

struct point{
	int x, y;
	point(int a = 0, int b = 0) : x(a), y(b){}
	void print(){
		std::cout << "(" << x << "," << y << ")\n";
	}
};

int main(){
	std::vector<point> v(10);
	for_each(v.begin(), v.end(), bind(&point::print, _1));
	return 0;
}
