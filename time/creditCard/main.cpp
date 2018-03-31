#include <iostream>
#include "credit_card.hpp"
using namespace std;

int main(){
	credit_card a("A bank", 25);			//A银行计账日是每月的25号
	credit_card b("B bank", 12);			//B银行计账日是每月的12号

	credit_card tmp = std::max(a, b);
	cout << "You should use " << tmp.bank_name << ", free days = " << tmp.calc_free_days() << endl;
	return 0;
}
