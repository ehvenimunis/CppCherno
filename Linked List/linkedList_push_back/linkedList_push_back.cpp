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

	int front()const { // const bir nesneyi değitiremez
		if (isEmty())
			throw "Error: list::front() for list is empty";
		else {
			return begin()->data;
		}
	}

	int back()const {
		if (isEmty())
			throw "Error: list::back() for list is empty";
		else {
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			return tmp->data;
		}
	}

	void pop_back() {
		if (isEmty())								// liste boş olmamalı
			throw "Error: list for list is empty";
		if (begin()->next == end()) {				// eğer bir tane eleman varsa
			delete root;
			root = NULL;
		}
		else {
			Node* tmp = begin();
			while (tmp->next->next != end())
				tmp = tmp->next;
			delete tmp->next;
			tmp->next = NULL;
		}
	}

	void pop_front() {
		if (isEmty())								// liste boş olmamalı
			throw "Error: list for list is empty";
		Node* tmp = root;
		root = tmp->next;
		delete tmp;
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

	// pop back 
	list.pop_back();
	list.pop_back();

	// pop front
	list.pop_front();
	list.traverse();

	return 0;
}

/*
	1
	0
	997 979 799 153 154 155 156
	front value in linked list : 997
	back value in linked list : 156
	979 799 153 154
*/