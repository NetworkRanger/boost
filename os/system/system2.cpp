#include <boost/system/system_error.hpp>
#include <iostream>
using namespace boost::system;

int main(){
	try{
		throw system_error(error_code(5, system_category()));	//抛出system_error异常
	}catch(system_error &e){
		std::cout << e.what();
	}
	return 0;
}
