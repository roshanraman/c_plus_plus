/***Single link list***/
//#include "stdafx.h'

#include "stdafx.h"
#include <memory>
#include <iostream>
#include<map>
#include <cstring>

struct MyPointer{
	MyPointer(int *p){ m_p = p; }
	~MyPointer(){ delete m_p; }
	void Add(int i){
		(*m_p) += i;
		std::cout << *m_p << std::endl;
}
private:
	int* m_p;
};
struct ltstr{
	bool operator()(const char*s1, const char*s2) const{
		return strcmp(s1, s2) < 0;
}
};

class SLL{
public:
	struct Node{
		int data;
		Node *next;
	};
	SLL(){}
	~SLL(){}


	Node *InsertIntoSOrtedList(Node *list, int num);
	void printList(Node *lst);
	Node* reverseList(Node *list);
	Node* reverseHalfOfList(Node* head,int );
	int getSize(Node*);
	void swapNodes(Node**, int, int);
	
private:
	Node *head;
};
typedef SLL::Node* NodePtr;
typedef SLL::Node NodeObj;

