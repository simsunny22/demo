#include <iostream>
#include <algorithm>

int find_close_num(int *a, int len, int sum);

int main () {
	int a[] = {5,43,12,43,32,13,87,90,15,25,9};


	std::cout << std::endl;
	find_close_num(a, 11, 60);
}                                               


int find_close_num(int *a, int len, int sum) {
	for(int i= 0; i < 11; i++) {
		std::cout << a[i] << " "; 
	}
	std::cout << std::endl;
	std::cout << "sum:" << sum << std::endl;
	std::sort(a, a+11);
	for(int i= 0; i < 11; i++) {
		std::cout << a[i] << " "; 
	}
	std::cout << std::endl;


	int i = 0, j = len-1;
	int min = a[i], max = a[j];

	int current_abs = 0;
	int last_abs = abs(2*max-sum) > abs(2*min-sum) ? 2*max : 2*min;

	int ret_i, ret_j;
	while(i < j) {
		int _i = i, _j = j;
		int _sum = a[i] + a[j];

		if (_sum > sum) {
			j--;	
		} else if (_sum < sum) {
			i++;
		} else {
			ret_i = _i, ret_j = _j;
			break;
		}

		current_abs = abs(_sum - sum);
		if (current_abs < last_abs) {
			last_abs = current_abs;
			ret_i = _i;
			ret_j = _j;
		}
	}
	std::cout << "res:" << a[ret_i] << std::endl;
	std::cout << "res:" << a[ret_j] << std::endl;
	return 0;
}
