#include <boost/smart_ptr/owner_less.hpp>
#include <memory>
#include <set>
#include <assert.h>

int main(){
	typedef std::shared_ptr<int> int_ptr;			//共享指针typedef
	typedef std::owner_less<int_ptr> int_ptr_less;	//函数对象typedef

	int_ptr p1(new int(10));						//共享指针
	int n = 20;									
	int_ptr p2(p1, &n);							//别名构造

	assert(!int_ptr_less()(p1, p2) && !int_ptr_less()(p2, p1));		///两者既不小于也不大于，即等价

	typedef std::set<int_ptr> int_set;			//关联容器typedef
	int_set s;

	s.insert(p1);								//插入两个元素
	s.insert(p2);								//因为等价所以不会被插入
	assert(s.size() == 1);						//实际容器里只有一个元素
	return 0;
}
