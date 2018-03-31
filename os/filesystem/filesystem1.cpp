#include <boost/filesystem.hpp>
using namespace boost::filesystem;

int main(){
	namespace fs = boost::filesystem;	//命名空间别名

	path ptest = "./test";
	if(exists(ptest)){		//检查路径是否存在
		if(fs::is_empty(ptest)){		//检查命名空间限定
			remove(ptest);		//remove只能删除空目录或文件
		}else{
			remove_all(ptest);	//remove_all可以递归删除
		}
	}

	assert(!exists(ptest));		//该目录已经被删除
	create_directory(ptest);	//创建一个目录

	copy_file("/usr/local/include/boost/verion.hpp", ptest / "a.txt");
	assert(exists(ptest / "a.txt"));

	rename(ptest / "a.txt", ptest / "b.txt");	//改名
	assert(exists(ptest / "b.txt"));

	//使用create_directories可以一次创建多级目录
	create_directories(ptest / "sub_dir1" / "sub_dir1");
	return 0;
}
