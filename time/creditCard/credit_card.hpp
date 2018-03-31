#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
using namespace std;
using namespace boost::gregorian;

class credit_card{
public:
	string bank_name;		//银行名
	int bill_day_no;		//计账日
	credit_card(const char *bname, int no) : bank_name(bname), bill_day_no(no){}		//构造函数
	int calc_free_days(date consume_day = day_clock::local_day())const{
		date bill_day(consume_day.year(), consume_day.month(), bill_day_no);			//得到计账日
		if(consume_day > bill_day){			//消费日是否已经超过了计账日
			bill_day += months(1);			//如果过了则是下个有的计账日
		}
		return (bill_day-consume_day).days() + 20;			//计算免息期
	}
	friend bool operator<(const credit_card& l, const credit_card& r){
		return l.calc_free_days() < r.calc_free_days();		//比较免息期
	}
};
