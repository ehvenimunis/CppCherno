// linkedList_push_back.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

class Node {
	public:
		Node(const int& data = 0, Node* next = NULL) : data(data), next(next) { } // consructor

		int data;
		Node* next;
};

class list {
	Node* root;
public:
	list() : root(NULL){ }
	Node* begin()const { return root; }
	Node* end()const { return NULL; }
	//bool isEmty()const { return root == NULL;  }
	bool isEmty()const { return root == end(); }

	void push_back(const int& value) {
		if (isEmty())
			root = new Node(value);
		else {
			Node* tmp = begin();
			while (tmp = begin())
				tmp = tmp->next;
			tmp->next = new Node(value);
		}
	}	
};

int main() {
	list list;
	cout << list.isEmty() << endl; // Get 1 value for empty
	list.push_back(1453);
	cout << list.isEmty() << endl; 
	return 0;
}