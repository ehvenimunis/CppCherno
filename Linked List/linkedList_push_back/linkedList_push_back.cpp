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
	bool isEmty()const { return begin() == end(); }

	void push_back(const int& value) {
		if (isEmty())
			root = new Node(value);
		else {
			Node* tmp = begin();
			while (tmp->next != end())
				tmp = tmp->next;
			tmp->next = new Node(value);
		}
	}	

	void traverse() {
		Node* first = begin();
		while (first != end()) {
			cout << first->data << " ";
			first = first->next;
		}
		cout << endl;
	}

	void push_front(const int& value) {
		if (isEmty())
			root = new Node(value);
		else {
			Node* tmp = new Node(value);
			tmp->next = root;
			root = tmp;
		}
	}

	int front()const {
		if (isEmty())
			throw "Error: lis::front() for list is empty";
		else {
			return begin()->data;
		}
	}

	int back()const {
		if (isEmty())
			throw "Error: lis::front() for list is empty";
		else {
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			return tmp->data;
		}
	}
};


int main() {

	// push back
	list list;
	cout << list.isEmty() << endl; // Get 1 value for empty
	list.push_back(153);
	cout << list.isEmty() << endl; 
	list.push_back(154);
	list.push_back(155);
	list.push_back(156);
	list.push_back(157);
	list.push_back(158);

	// push front
	list.push_front(799);
	list.push_front(979);
	list.push_front(997);

	// traverse in linked list
	list.traverse();

	// front value
	cout << "front value in linked list : " << list.front() << endl;

	// back value
	cout << "back value in linked list : " << list.back() << endl;


	return 0;
}

/*
	1
	0
	153 154 155 156 157 158
*/