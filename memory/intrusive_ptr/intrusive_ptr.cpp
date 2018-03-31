#include <boost/smart_ptr.hpp>
using namespace boost;

int main(){
	typedef intrusive_ptr<counted_data> counted_ptr;		//类型定义

	counted_ptr p(new counted_data);						//创建智能指针
	assert(p);												//bool转型
	assert(p->m_count == 1);								//operator->

	counted_ptr p2(p);										//指针拷贝构造
	assert(p->m_count == 2);								//引用计数增加

	counted_ptr weak_p(p.get(), false);						//弱引用
	assert(weak_p->m_count() == 2);							//引用计数不增加

	p2.reset();												//复位指针
	assert(!p2);											//p2不支持有指针
	assert(p->m_count == 1);								//引用计数减少
															//对象被正确析构
	return 0;
}
