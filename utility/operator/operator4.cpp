#include <boost/core/explict_operator_bool.hpp>

struct demo_a{
	BOOST_EXPLICT_OPERATOR_BOOL()			//定义显示bool转型操作符
	bool operator!()const{					//定义operator！
		return false;
	}
};

struct demo_b{
	BOOST_EXPLICT_OPERATOR_BOOL_NOEXCEPT()		//定义显示bool转型操作符
	bool operator!()const{						//定义operator!
		return true;
	}
};

demo_a a;
demo_b b;
assert(a && !b);
	
