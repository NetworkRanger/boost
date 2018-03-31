#include <boost/assign.hpp>
#include <stack>
#include <queue>
#include <iostream>
#include <string>

int main(){
	using namespace boost::assign;

	std::stack<int> stk = (list_of(1), 2, 3).to_adapter();
	stk += 4, 5, 6;
	for(;!stk.empty();){			//输出stack的内容
		std::cout << stk.top() << " ";
		stk.pop();
	}
	std::cout << std::endl;

	std::queue<std::string> q = (list_of("china")("us")("uk")).repeat(2, "russia").to_adapter();
	push(q)("germany");
	for(;!q.empty();){
		std::cout << q.front() << " ";
		q.pop();
	}
	std::cout << std::endl;

	std::priority_queue<double> pq = (list_of(1.414), 1.732, 2.236).to_adapter();
	push(pq), 3.414, 2.71828;
	for(;!pq.empty();){				//输出优先队列的内容
		std::cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}
