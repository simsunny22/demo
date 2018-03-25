#include <iostream>

using namespace std;


// rigit and left value
void test_lr_value() {
    int   i =1 ;
	int&  l_ref = i;
	int&& r_ref = 2;
    //int&& r_ref = i; //compile error(because i is l_value)
	std::cout << "l_ref:" << l_ref << std::endl;
	std::cout << "r_ref:" << r_ref << std::endl;
    std::cout << "**********************" << std::endl;
}

// rigit value
void processValue(int& a) {
	cout << "process_left_val" << endl; 
}

void processValue(int&& a) { 
    cout << "process_right_val" << endl;
}

void forward_value(int& val) {
	cout << "forward_left_val"  << endl;
    processValue(val); 
}

void forward_value(int&& val) {
	cout << "forward_right_val" << endl;
    processValue(val); 
}

void test_right_value() {
	int i = 1;
	forward_value(i);
	forward_value(2);
    std::cout << "**********************" << std::endl;
}

//forward value
template <typename T>
void forwardValue(T&& val)
{
    processValue(std::forward<T>(val));
}

void test_forward_value(){
    int i = 1;
    forwardValue(i);
    forwardValue(2);
    std::cout << "**********************" << std::endl;
}

int main(){
    test_lr_value();
	test_right_value();
    test_forward_value();
}
