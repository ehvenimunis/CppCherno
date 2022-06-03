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
	Node* tail;
public:
	list() {  // costructor
		root = new Node();
		tail = root;
		tail->next = new Node();
	} 

	Node* begin()const { return root->next; } // constructorda yapılan işlem neticesinde begin ve end metodu aynı yere işaret eder. 
	Node* end()const { return tail->next; }
	//bool isEmty()const { return root == NULL;  }
	bool isEmty()const { return begin() == end(); }

	void push_back(const int& value) {
		insert(end(), value);
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
		insert(begin(), value);
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

	void insert(Node* pos, const int& value) {
		if (pos == end()) { // eğer son elemana işaret ediyorsa
			tail->next = new Node(value, end());
			tail = tail->next;
		}
		else { // araya ya da başa eleman ekleme olabilir
			Node* tmp = root;
			while (tmp->next != pos) {
				tmp = tmp->next; // ileriye kaydır
				tmp->next = new Node(value, tmp->next);
			}
		}
	}
};


int main() {

	// push back
	list list;
	cout << list.isEmty() << endl;
	list.push_front(55);
	list.traverse();
	cout << list.isEmty() << endl;
	list.push_back(88);
	list.traverse();

	list.insert(list.begin(), 44);

	list.traverse();
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