#include <boost/progress.hpp>
#include <string>
#include <vector>
#include <fstream>
using namespace boost;

int main(){
	std::vector<std::string> v(100);					//一个字符串向量
	std::ofstream fs("./test.txt");						//文件输出流

	//声明一个progreee_display对象，基数是v的大小
	progress_display pd(v.size());

	//开始迭代遍历向量，处理字符串，写入文件
	for(auto& x : v){
		fs << x << std::endl;
		++pd;
	}
	return 0;
}
