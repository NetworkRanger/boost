#include <boost/unordered_set.hpp>
#include <boost/functional/hash.hpp>
using namespace boost;

struct demo_class{
	int a;
	friend bool operator==(const demo_class &l, const demo_class &r){
		return l.a == r.a;
	}
};

size_t hash_value(demo_class &s){
	return boost::hash<int>()(s.a);
}

int main(){
	unordered_set<demo_class> us;
	return 0;
}
