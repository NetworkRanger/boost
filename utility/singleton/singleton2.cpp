#include <boost/serialization/singleton.hpp>
#include <iostream>
using boost::serialization::singleton;

class point : public singleton<point>{		//注意这里
	
};

int main(){
	std::cout << "main() start" << std::endl;

	point::get_const_instance().print();
	point::get_mutable_instance().print();

	std::cout << "main() finish" << std::endl;
	return 0;
}
