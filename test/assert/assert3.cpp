#include <boost/format.hpp>
namespace boost{		//namespace boost
	void assert_failed(char const *, char const *, char const *, long){}
	void assert_failed(char const * expr, char const *msg, char const *function, char const *file, long line){
		boost::format fmt("Assertion failed!\nException: %s\n", 
						  "Function: %s\nFile: %s\nLine: %ld\n",
						  "Msg: %s\n\n");
		fmt % expr % function % file % line % msg;
		std::cout << fmt;
	}
}

#define BOOST_ENABLE_ASSERT_HANDLER	//启用handler
#include <boost/assert.hpp>

double func(int x){}
int main(){
	func(0);		//error
}

