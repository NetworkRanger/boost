#include <boost/assign.hpp>
#include <cstdlib>				//for rand()
#include <vector>
#include <set>
#include <deque>

int main(){
	using namespace boost::assign;

	std::vector<int> v = list_of(1).repeat(3, 2)(3)(4)(5);
	//v = 1, 2, 2, 2, 3, 4, 5
	
	std::multiset<int> ms;
	insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;
	//ms = x, x, x, x, x, x, 1, 1, 10
	
	std::deque<int> d;
	push_front(d).range(v.begin(), v.begin() + 5);
	//d = 3, 2, 2, 2, 1
	return 0;
}
