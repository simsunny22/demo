
//struct List {
//	int *a;
//	int len;
//}


#include <time.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

#define LIST_NUM 5
#define LIST_MAX_SIZE 10
#define LIST_MAX_NUM 200



struct Record {
	int value;
	int list_index;
	int array_index;
	Record(int val, int list_idx, int array_idx):
		value(val),list_index(list_idx),array_index(array_idx) {
	}
};

struct NodeList {
	int 	 value;
	NodeList *next;
	NodeList(int val):value(val),next(NULL){}
};

struct greater {
	bool operator ()(NodeList* a, NodeList* b) {
		return a->value > b->value;
	}
};

NodeList* make_sort_list();
std::vector<NodeList*> make_vlist();

NodeList* merge(std::vector<NodeList*>& vlist);
void print_node_list(NodeList* node);


int main() {
	unsigned seed = time(0);
	srand(seed);

	std::vector<NodeList*> vlist = make_vlist();
	std::cout  <<  "=========i============" << std::endl;
	NodeList* head = merge(vlist);	
	print_node_list(head);
}

std::vector<NodeList*> make_vlist() {
	std::vector<NodeList*> list;
	for (int i = 0 ; i < LIST_NUM; i++) {
		std::cout  <<  "=========" << std::endl;
		NodeList* head = make_sort_list();
		print_node_list(head);
		list.push_back(head);
	}
	return list;
}

NodeList* make_sort_list() {
	int len = rand() % LIST_MAX_SIZE + 1;
	
	int* array = new int[len];
	for(int i = 0; i < len; i++) {
		array[i] = rand() % LIST_MAX_NUM;
	}

	std::sort(array, array+len);

	
	NodeList* head = new NodeList(array[0]);
	NodeList* node = head;

	for (int i = 1; i < len; i ++) {
		NodeList* _node = new NodeList(array[i]);
		node->next = _node;
		node = _node;
	}

	return head;
	
}

NodeList*  merge(std::vector<NodeList*>& vlist) {
	std::priority_queue<NodeList*, std::vector<NodeList*>, greater> heap;
	for (int i = 0; i < vlist.size(); i++) {
		heap.push(vlist[i]);
	}


	NodeList* min_node = heap.top();
	heap.pop();
	printf("%d, ", min_node->value);

	NodeList* head = new NodeList(min_node->value);
	NodeList* node = head;
	if(min_node->next != NULL) {
		heap.push(min_node->next);
	}
	while(!heap.empty()) {
		min_node = heap.top();
		heap.pop();
		printf("%d, ", min_node->value);

		NodeList* _node = new NodeList(min_node->value);
		node->next = _node;
		node = _node;
		
		if(min_node->next != NULL) {
			heap.push(min_node->next);
		}
	}
	printf("\n");

	return head;
} 

void print_node_list(NodeList* node) {
	while(node) {
		printf("%d, ", node->value);
		node = node->next;
	}
	printf("\n");
}



