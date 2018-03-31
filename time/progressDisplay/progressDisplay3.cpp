#include <boost/progress.hpp>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
using namespace boost;

int main(){
	vector<string> v(100, "aaa");

	v[10] = "";
	v[23] = "";
	ofstream fs(".test.txt");
	progress_display pd(v.size());

	for(auto pos=v.begin();pos!=v.end();++pos){
		fs << *pos << endl;
		//++pd;
		if(pos->empty()){
			pd.restart(v.size());
			pd += (pos-v.begin()+1);
			cout << "null string # " << (pos - v.begin()) << endl;
		}
	}
	return 0;
}
