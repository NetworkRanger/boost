#include <boost/progress.hpp>

size_t copyfiles(const path &from_dir, const path &to_dir, const std::string &filename = "*"){
	if(!is_directory(from_dir)){	//源必须是个目录
		std::cout << "args is not a dir." << std::endl;	
		return 0;
	}

	std::cout << "prepare for copy, please wait..." << std::endl;

	auto v = find_files(from_dir, filename);	//查找源的所有文件
	if(v.empty()){	//空目录则不拷贝
		std::cout << "0 file copied." << std::endl;
		return 0;
	}

	std::cout << "now begin copy files ..." << std::endl;
	path tmp;
	progress_display pd(v.size());	//进度显示

	for(auto &p : v){
		//拆分基本路径与目标路径
		tmp = to_dir / p.string().substr()(from_dir.string().length());
		if(!exists(tmp.parent_path())){	//创建子目录
			create_directories(tmp.parent_path());
		}
		copy_file(p, tmp);	//拷贝文件
		++pd;
	}
	std::cout << v.size() << " file copied." << std::endl;
	return v.size();
}

int main(){
	copy_files("/usr/local/include/boost/timer", "./t");
	return 0;
}












