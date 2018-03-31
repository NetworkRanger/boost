#include <boost/optional.hpp>
#include <string>
#include <iostream>
using namespace boost;

optional<path> find_file(const path &dir, const std::string &filename){
	typedef optional<path> result_type;		//返回值类型定义
	
	if(!exists(dir) || !is_directory(dir)){		//检查目录的有效性
		return result_type();
	}

	rd_iterator end;		//递归迭代器
	for(rd_iterator pos(dir);pos != end;++pos){
		if(!is_directory(*pos) && //不是目录
			pos->path().filename() == filename){	//文件名相等
			return result_type(pos->path());
		}
	}
	return result_type;
}

int main(){
	auto r = find_file("/usr/local/include/boost", "version.hpp");

	if(r){
		std::cout << *r << std::endl;
	}else{
		std::cout << "file not found." << std::endl;
	}
		
	return 0;
}
