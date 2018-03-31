#include <boost/exception/all.hpp>
#include <boost/throw_exception.hpp>			//BOOST_THROW_EXCEPTION
#include <iostream>
using namespace boost;

struct my_err{};				//自定义的异常类

int main(){
	try{
		//使用enable_error_info包装自定义异常
		throw enable_error_info(my_err())
		<< errinfo_errno(101)
		<< errinfo_api_function("fopen");
	}catch(boost::exception &e){
		std::cout << diagnostic_information(e) << std::endl;
	}

	try{
		BOOST_THROW_EXCEPTION(std::logic_error("logic"));		//必须是标准异常
	}catch(boost::exception &e){
		std::cout << diagnostic_information(e) << std::endl;
	}
	return 0;
}
