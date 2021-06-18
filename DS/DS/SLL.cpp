#include "stdafx.h"
#include "SLL.h"

using namespace std;

NodePtr SLL::InsertIntoSOrtedList(NodePtr lst, int num)
{
	NodePtr node = new NodeObj;
	node->next = NULL;
	node->data = num;

	if (lst == NULL)
		return node;
	else if (lst->next == NULL && num >= lst->data){
		lst->next = node;
		return lst;
	}
	else if (lst->next == NULL || num < lst->data){
		node->next = lst;
		return node;
	}
	else
	{
		NodePtr temp1 = lst;
		NodePtr temp2 = lst->next;
		while (temp2){
			if (num >= temp1->data && num < temp2->data)
			{
				temp1->next = node;
				node->next = temp2;
				return lst;
			}
			if (num >= temp2->data && temp2->next == NULL)
			{
				temp2->next = node;
				return lst;
			}
			else
			{
				temp1 = temp1->next;
				temp2 = temp2-> next;
			}

			/*
			if (num > temp1->data && num >= temp2->data && temp2->next == NULL)
			{

			}
			else if (num > temp2->data){
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else if (num >= temp1->data){
				temp1->next = node;
				node->next = temp2;
				return lst;
			}
			else{
				node->next = temp1;
				return lst;
			}*/
		}
	}

	return lst;
}

void SLL::printList(NodePtr head)
{
	NodePtr temp = head;
	cout << "\n";
	while (temp)
	{
		cout << temp->data <<"\t";
		temp = temp-> next;
	}
} 

NodePtr SLL::reverseList(NodePtr list){
	//printList(head);

	NodePtr p1, p2, temp;
	p1 = list;
	p2 = p1->next;
	temp = p2;
	p1->next = NULL;
	
	while (temp){
		temp = p2->next;
		p2->next = p1;
		p1 = p2;
		//head = p2;
		p2 = temp;
	}

	return p1;
}

int SLL::getSize(NodePtr list){
	int size = 0;
	while (list){
		size++;
		list = list->next;
	}
	return size;
}

NodePtr SLL::reverseHalfOfList(NodePtr head, int partOfList){
	int size = 0;
	NodePtr temp = head;
	int i = 0;
	temp = head;
	NodePtr prevNode=NULL;
	while (i < partOfList){
		cout << "\nData : " << temp->data;
		prevNode = temp;
		temp = temp->next;
		i++;		
	}
	NodePtr reversedList = reverseList(temp);
	prevNode->next = reversedList;
	return head;
}

void SLL::swapNodes(Node **head, int key1, int key2){
	if (key1 == key2){
		cout << "\nBoth keys are same..returning";
		return;
	}
	Node *prevFirst = NULL, *first = NULL, *prevSecond = NULL, *second = NULL, *temp = NULL, *curr = *head;
	bool bFoundFirst = false, bFoundSecond = false;
	/*search for both keys*/
	while (curr && (!bFoundFirst || !bFoundSecond)){
		if (curr->data == key1 || curr->data == key2)
		{
			if ((curr->data == key1) && !(bFoundFirst)){
				bFoundFirst = true;
				first = curr;
			}
			if ((curr->data == key2) && !(bFoundSecond)){
				bFoundSecond = true;
				second = curr;
			}
		}
		if (!bFoundFirst)
			prevFirst = curr;
		if (!bFoundSecond)
			prevSecond = curr;

		curr = curr->next;
	}
	/*Swap Nodes*/
	if (bFoundFirst && bFoundSecond){
		temp = second->next;
		if (prevFirst)	//Check for head node
			prevFirst->next = second;
		prevSecond->next = first;
		second->next = first->next;	
		first->next = temp;
		
		/*check if head data is first or second key*/
		if (!prevFirst && bFoundFirst)
			*head = second;
		if (!prevSecond && bFoundSecond)
			*head = first;
	}
	else
		cout << "\nKey not found" << endl;
}

