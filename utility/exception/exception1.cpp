#include <boost/exception/all.hpp>
using namespace boost;

int main(){
	try{
		try{
			throw my_exception() << err_no(10);			//抛出异常，存储错误码
		}catch(my_exception &e){
			//获得异常内存信息
			std::cout << *get_error_info<err_no>(e) << std::endl;
			std::cout << e.what() << std::endl;
			e << err_str("other info");					//向异常追加信息
			throw;										//再次抛出异常
		}
	}catch(my_exception &e){
		std::cout << *get_error_info<err_str>(e) << std::endl;		//获得异常信息
	}
	return 0;
}
