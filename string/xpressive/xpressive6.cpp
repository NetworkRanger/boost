#include <boost/xpressive/xpressive_dynamic.hpp>
#include <iostream>
#include <string>

int main(){
	using namespace boost::xpressive;

	std::string str("Power-bomb, power-suit, pOWER-beam all items\n");

	sregex reg = sregex::compile("power-(\\w{4})", icase);

	sregex_iterator pos(str.begin(), str.end(), reg);
	sregex_iterator end;
	for(;pos != end;++pos){
		std::cout << "[" << (*pos)[0] << "]";
	}
	std::cout << std::endl;
	return 0;
}
