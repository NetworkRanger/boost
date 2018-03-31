int main(){
	options_description opts("demo optins");

	std::string filename;	//外部的选项值存储
	opts.add_options();		//产生辅助对象，调用operator()
		//帮助选项，使用空格缩进格式
		("help,h", "help message\n a bit of long text")
		//文件名选项，值可存储到外部，默认是test
		("filename,f", value<std::string>(&filename)->default_value("test"), "to find a file")
		//搜索路径选项，可以多次出现，可以接受多个记号
		("dir,D", value<std::vector<std::string> >()->multioken(), "search dir")
		//搜索深度选项，隐藏值是5，知名与搜索路径不同
		("depth,d", value<int>()->implicit_value(5), "search depth");

	variables_map vm;		//选项存储map容器
	store(parse_command_line(argc, argv, opts), vm);	//解析
	notify(vm);		//解析结果存储外部变量

	//解析完成，调用函数实现选项处理逻辑
	print_vm(opts, vm);
	return 0;	
}

void print_vm(options_description &opts, variables_map &vm){
	if(vm.empty()){
		std::cout << opts << std::endl;
		return;
	}
	if(vm.count("help")){
		std::cout << opts<< std::endl;
	}

	//输出查找文件名,因为它有默认值，故总存在
	std::cout << "find opt:" << vm["filename"].as<std::string>() << std::endl;

	if(vm.count("dir")){
		std::cout << "dir opt:";
		for(auto &str : vm["dir"].as<std::vector<std::string> >()){
			std::cout << str << " ";
		}
		std::cout << std::endl;
	}
	if(vm.count("depth")){
		std::cout << "depth opt:" << vm["depth"].as<int>() << std::endl;
	}
}




















