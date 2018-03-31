#include <utility>
#include <assert.h>

class demo_class{
public:
	demo_class(int n) : x(n){}
	int x;
	friend bool operator<(const demo_class &l, const demo_class &r){
		return l.x < r.x;
	}
};

int main(){
	demo_class a(10), b(20);
	using namespace std::rel_ops;			//打开std::rel_ops名字空间

	assert(a<b);							//自定义的<操作符
	assert(a>=b);							//>=等操作符被自动实现
	return 0;
}
