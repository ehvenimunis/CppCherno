//============================================================================
// Name        : linkedList.cpp
// Author      : Muhamemd Salih Aydoğan
// Version     :
// Description : A simple CPP program to introduce a linked list
//============================================================================

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	
	Node() {
		cout << "Constructor" << endl;
	}

	~Node() {
		cout << endl << "Destructor";
	}

};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

// Driver code
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;

	printList(head);

	delete head;
	delete second;
	delete third;

	return 0;
}

/*
 * 		Output :
 * 			1 2 3
 */

 /*
 
 Linked list, pointerlar kullanılarak oluşturulmuş bir listedir. Bir linked list, sabit bir boyuta sahip değildir. Program çalışıyorken boyut( size) büyüyebilir ya da küçülebilir. Tree, pointerlar kullanılarak oluşturulmuş bir başka veri yapısıdır.

 Bir linked list, dinamik veri yapısının basit bir örneğidir. Dinamik veri yapısı olarak adlandırılmasının sebebi, sahip olduğu her değişkenin new operatörüyle dinamik olarak oluşturulmasıdır. Linked listler head ve node’lardan oluşur.

 Heap Memory, bellek üzerinde yer tahsisi yapılan belli bir bölümdür. Bu yer, bellek üzerinde “malloc” fonksiyonu aracılığıyla tahsis edilir ve heap üzerinde allocate edilen(yer tahsisi yapılan) bellek “free” lenerek tekrar kullanım için serbest bırakılır. Heap’teki bellek kullanımı compiler tarafından değil, geliştiriciler tarafından kontrol edilir. Karmaşık programlar oluştururken, genellikle büyük bir bellek alanına ihtiyaç duyarız. Bu durumda Heap Memory kullanırız. Heap üzerinde allocate ettiğimiz bellek operasyonuna “dynamic memory allocation” adı verilir.

 Eğer program esnasında boyutları bildirilmiş değişmez bir değer kullanıyorsak stack, değişebilir bir değer kullanıyorsak heap bizim için uygun olacaktır. Stack compailer tarafından yönetilir. Stack kullanılır ve işi bittikten sonra kendini otomatik olarak bellekten yok eder. Fakat heap‘te bu işi siz yapmalısınız. 


 */