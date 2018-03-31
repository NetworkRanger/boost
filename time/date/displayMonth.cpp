#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;
using namespace boost::gregorian;

int main(){
	date d(2008, 11, 20);
	date d_start(d.year(), d.month(), 1);	//当月第一天
	date d_end(d.end_of_month());			//当月最后一天

	for(day_iterator d_iter(d_start);d_iter<=d_end;++d_iter){
		cout << *d_iter << " " << d_iter->day_of_week() << endl;
	}
	return 0;
}
