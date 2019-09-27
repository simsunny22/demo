#include <iostream>
#include <algorithm>


class Result {
public:
	Result(int i, int j) {
		set(i, j);
	}

	void set(int i, int j) {
		this->i = i;
		this->j = j;
	}
	void print(int num) {
		std::cout << "i:" << this->i << ",j:" << this->j << std::endl;
		std::cout << "sum:" << this->i+ this->j << ",num:" << num << std::endl;
	}
private:
	int i;
	int j;
};

Result find_close_num(int *a, int len, int sum);

int main () {
	int a[] = {5,43,12,43,32,13,87,90,15,25,9};

	std::cout << std::endl;
	Result result = find_close_num(a, 11, 60);
	result.print(60);
}                                               

void print_list(int *a, int len) {
	for(int i= 0; i < 11; i++) {
		std::cout << a[i] << " "; 
	}
	std::cout << std::endl;

}

Result find_close_num(int *a, int len, int num) {
	//sort array
	print_list(a, len);
	std::sort(a, a+11);
	print_list(a, len);

	Result result(0,0);
	int i = 0, j = len-1;
	int current_abs = 0;
	int min = a[i], max = a[j];
	int last_abs = abs(2*max-num) > abs(2*min-num) ? 2*max : 2*min;

	while(i < j) {
		int _i = i, _j = j;
		int _sum = a[i] + a[j];

		if (_sum > num) {
			j--;	
		} else if (_sum < num) {
			i++;
		} else {
			result.set(a[_i], a[_j]);
			break;
		}

		current_abs = abs(_sum - num);
		//if current_abs < last_abs, means more close, so record result
		if (current_abs < last_abs) {
			last_abs = current_abs;
			result.set(a[_i], a[_j]);
		}
	}
	return result;
}
