#include <boost/filesystem/fstream.hpp>
namespace newfs = boost::filesystem;

int main(){
	path p("./INSTALL");
	newfs::ifstream ifs(p);
	assert(ifs.is_open());
	std::cout << ifs.rdbuf();
	return 0;
}
