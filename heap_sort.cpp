#include <iostream>

void build_heap(int *a, int len);
void sort_heap(int *a, int len);
void print_list(int *a, int len);

int main() {
	int a[] = {4,6,1,57,52,54,6,24,13,41,4};
	print_list(a, 11);
	build_heap(a, 11);
	print_list(a, 11);
	sort_heap(a, 11);
	print_list(a, 11);
}

void exchange(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void adjust_heap(int *a, int last_idx, int current_idx) {
	if (current_idx > last_idx) {
		return ;
	}
	
	int max_idx = current_idx;
	//here first_idx = 0 , not 1;
	int left_child_idx = current_idx  * 2 + 1;
	int right_child_idx = current_idx * 2 + 2;

	if (left_child_idx < last_idx && a[left_child_idx] > a[max_idx]) {
		max_idx = left_child_idx;
	}

	if (right_child_idx < last_idx && a[right_child_idx] > a[max_idx]) {
		max_idx = right_child_idx;
	}

	if (max_idx != current_idx) {
		exchange(a[current_idx], a[max_idx]);
		return adjust_heap(a, last_idx, max_idx);
	}
}

void build_heap(int *a, int len) {
	int last_index = len-1;
	//here first_idx = 0 , not 1;
	for(int i=(last_index-1)/2; i>=0; i--) {
		adjust_heap(a, last_index, i);
	}
}

void sort_heap(int *a, int len) {
	for(int last_index = len - 1; last_index > 0;  last_index--) {
		exchange(a[0], a[last_index]);
		adjust_heap(a, last_index-1, 0);
	}
}

void print_list(int *a, int len) {
        for(int i= 0; i < len; i++) {
                std::cout << a[i] << " ";
        }
        std::cout << std::endl;

}
