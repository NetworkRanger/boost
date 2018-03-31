#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;
using namespace boost::gregorian;

int main(){
	date d(2008, 11, 20);			//声明日期对象

	date d18years = d+years(18);
	cout << d18years << " is " << d18years.day_of_week() << endl;		//加上18年

	int count = 0;					//星期天的计数器
	for(day_iterator d_iter(date(d18years.year(), 11, 1));d_iter<=d18years.end_of_month();++d_iter){
		if(d_iter->day_of_week() == Sunday){
			++count;			//是星期则计数增加
		}
	}
	cout << "total " << count << " Sundays." << endl;

	count = 0;						//计数器归零
	for(month_iterator m_iter(date(d18years.year(), 1, 1));m_iter<date(d18years.year()+1, 1, 1);++m_iter){
		count += m_iter->end_of_month().day();			//累加月份的天数
	}
	cout << "total " << count << " days of year." << endl;
	return 0;
}
