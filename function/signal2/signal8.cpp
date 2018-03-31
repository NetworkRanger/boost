class ring{
public:
	typedef signal<void()> signal_t;		//内部类型定义
	typedef signal_t::slot_type slot_t;

	connection connect(const slot_t &s){	//连接插槽
		return alarm.connect(s);
	}
	void press(){	//按门铃动作
		std::cout << "Ring alarm..." << std::endl;
		alarm();		//调用signal，发出信号，引发插槽调用
	}
private:
	signal_t alarm;		//信号对象
};

typedef variate_generator<rand48, uniform_smallint<> > bool_rand;
bool_rand g_rand(rand48(time(0)), uniform_smallint<>(0,100));

extern char const nurse1[] = "Mary";
extern char const nurse2[] = "Kate";

template<char const *name>
class nurse{
private:
	bool_rand &rand;		//随机数发生器
public:
	nurse() : rand(g_rand){}
	void action(){
		std::cout << name;
		if(rand() > 20){		//70%的概率惊醒
			std::cout << " wakeup and open the door." << std::endl;
		}else{		//20%的概率继续睡觉
			std::cout << " is sleeping..." << std::endl;
		}
	}
};

extern char const baby1[] = "Tom";
extern char const baby2[] = "Jerry";

tempate<char const *name>
class baby{
private:
	bool_rand &rand;
public:
	baby() : rand(g_rand()){}
	void action{
		std::cout << "Baby " << std::endl;
		if(rand() > 50){
			std::cout << " wakeup and crying loudly..." << std::endl;
		}else{
			std::cout << " is sleeping sweetly..." << std::endl;
		}
	}
};

class guest{
public:
	void press(ring &r){
		std::cout << "A guest press the ring." << std::endl;
		r.press();
	}
};

int main(){
	//声明门铃、护士、婴儿、访客等类的实例
	ring r;		//门铃
	nurse<nurse1> n1;	//护士1
	nurse<nurse2> n2;	//护士2
	baby<baby1> b1;		//婴儿1
	baby<baby2> b2;		//婴儿2
	guest g;			//访客

	//把护士、婴儿与门铃连接起来
	r.connect(bind(&nurse<nurse1>::action, n1));
	r.connect(bind(&nurse<nurse2>::action, n2));
	r.connect(bind(&baby<baby1>::action, b1));
	r.connect(bind(&baby<baby2>::action, b2));

	//访客按门铃，触发一系列的事件
	g.press(r);
	return 0;
}




















