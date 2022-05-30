// linkedListA.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	Node(const T& data = T(), Node<T>* next = NULL) : data(data), next(next){ } // consructor
	
	T data;
	Node<T>* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node<int>* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

// Driver code
int main()
{
	Node <int>* n1 = new Node<int>(3);
	Node <int>* n2 = new Node<int>(5);
	Node <int>* n3 = new Node<int>(10);
	n1->next = n2;
	n2->next = n3;

	// Simple print for all data
	cout << n1->data << " ";
	cout << n1->next->data << " ";
	cout << n1->next->next->data << endl; // sondaki elamana gitmek için ilk eleman üzerinden ilerledik

	Node<int>* tmp = n1;
	printList(tmp);

	return 0;
}

/*
 * 		Output :
 * 			3 5 10
 *  		3 5 10
 */