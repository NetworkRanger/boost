#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;
using namespace boost::gregorian;

int main(){
	date d1(2000, 1, 1);
	date d2(2014, 11, 18);
	cout << d2 - d1 << endl;			//5435天
	assert(d1+(d2-d1) == d2);

	d1 += days(10);						//2000-1-11
	assert(d1.day() == 11);
	d1 += months(2);					//2000-3-11
	assert(d1.month() == 3 && d1.day() == 11);
	d1 -= weeks(1);						//2000-3-04
	assert(d1.day() == 4);

	d2 -= years(10);					//2004-11-18
	assert(d2.year() == d1.year()+4);	
	return 0;
}
