#include <boost/program_options.hpp>
using namespace boost::program_options;

int main(int argc, char **argv){
	options_description opts("demo options");

	opts.add_options()	//增加两个程序选项
	("help", "just a help info")	//帮助选项
	("filename", value<std::string>(), "to find a file");	//文件名选项

	variables_map vm;	//选项存储map容器
	store(parse_command_line(argc, argv, opts), vm);	//解析存储

	//解析完成,实现选项处理逻辑
	if(vm.count("help")){	//处理帮助选项
		std::cout << opts << std::endl;		//输出帮助信息 
		return 0;
	}
	if(vm.count("filename")){	//要查找的文件名
		std::cout << "find " << vm["filename"].as<std::string>() << std::endl;
	}
	if(vm.empty()){		//没有任何选项参数
		std::cout << "no options" << std::endl;
	}
	return 0;
}
