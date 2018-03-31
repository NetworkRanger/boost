#include <boost/xpressive/xpressive_dynamic.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost::xpressive;

std::vector<path> find_files(const path &dir, const std::string &filename){
	static xpressive::sregex_compiler rc;	//正则表达式工厂
	if(!rc[filename].regex_id()){
		std::string str = replace_all_copy(replace_all_copy(filename, ",", "\\"), "*", ".*");		//处理文件名
		rc[filename] = rc.compile(str);	//创建正则表达式
	}

	typedef std::vector<path> result_type;	//返回值类型定义
	result_type v;

	if(!exists(dir) || !is_directory(dir)){	//目录检查
		return v;
	}

	rd_iterator end;	//递归迭代器愈尾位置
	for(rd_iterator pos(dir);pos != end;++pos){
		if(!is_directory(*pos) && regex_match(pos->path().filename().string(), rc[filename])){
			v.push_back(pos->path());		//找到，加入vector
		}
	}
	return v;
}
	
