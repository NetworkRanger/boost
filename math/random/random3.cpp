#include <boost/random.hpp>
#include <boost/nondet_random.hpp>
using namespace boost;

class boost::random_device::impl{};

int main(){
	//通常用法
	random_device rng;
	for(int i=0;i<10;++i){
		std::cout << rng() << ",";
	}
	std::cout << std::endl;

	//配合分布器
	uniform_real<> ur(1.0, 2.0);
	for(int i=0;i<10;++i){
		std::cout << ur(rng) << ", ";
	}
	std::cout << std::endl;

	//配合变量发生器
	variate_generator<random_device &, uniform_smallint<> > gen(rng, uniform_smallint<>(0, 255));
	for(int i=0;i<10;++i){
		std::cout << gen() << ", ";
	}
	std::cout << std::endl;
	return 0;
}
