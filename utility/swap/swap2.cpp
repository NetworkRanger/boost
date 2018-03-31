void swap(point &x, point &y){				//全局域的swap函数
	x.swap(y);
}

int main(){
	point a(1, 2, 3), b(4, 5, 6);

	std::cout << "std::swap" << std::endl;
	std::swap(a, b);				//调用std::swap

	std::cout << "boost::swap" << std::endl;
	boost::swap(a, b);				//调用boost::swap
	return 0;
}
