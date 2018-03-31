#include <string>
#include <stdlib.h>
#include <assert.h>

template<typename T>
T std_lexical_cast(const std::string &s);		//自定义模版转换函数

template<>
int std_lexical_cast<int>(const std::string &s){ //特化为int
	return stoi(s);			//调用stoi
}

template<>
long std_lexical_cast<long>(const std::string &s){	//特化为long
	return stol(s);			//调用stol
}

int main(){
	assert(std_lexical_cast<int>(" 10 ") == 10);
	assert(std_lexical_cast<int>("100L") == 100L);
	return 0;
}

