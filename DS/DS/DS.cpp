// DS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SLL.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	SLL* lst = new SLL();
	//lst->test();

	NodePtr head = lst->InsertIntoSOrtedList(NULL, 1);
	//cin >> i;
	head = lst->InsertIntoSOrtedList(head, 2);
	//cin >> i;
	head = lst->InsertIntoSOrtedList(head, 3);
	//cin >> i;
	head = lst->InsertIntoSOrtedList(head, 4);
	//cin >> i;
	head = lst->InsertIntoSOrtedList(head, 5);
	head = lst->InsertIntoSOrtedList(head, 6);
	head = lst->InsertIntoSOrtedList(head, 7);
	head = lst->InsertIntoSOrtedList(head, 8);
	head = lst->InsertIntoSOrtedList(head, 9);
	head = lst->InsertIntoSOrtedList(head, 10);
	head = lst->InsertIntoSOrtedList(head, 11);
	lst->printList(head);
	//delete lst;
	//B obj(10);
	lst->swapNodes(&head, 4, 5);
	lst->printList(head);

	//head = lst->reverseHalfOfList(head,lst->getSize(head)/3);
	//lst->printList(head);

	/*map<const char*, int, ltstr> Months;
		Months["january"] = 31;
		Months["february"] = 28;
		Months["march"] = 31;
		Months["april"] = 30;
		Months["may"] = 31;
		Months["june"] = 30;
		Months["july"] = 31;
			Months["august"] = 31;
	Months["september"] = 30;
	Months["october"] = 31;
	Months["november"] = 30;
		Months["december"] = 31;
	map<const char*, int, ltstr>::iterator curr = Months.find("june");
	map<const char*, int, ltstr>::iterator prev = curr;
	map<const char*, int, ltstr>::iterator next = curr;
	++next;
	--prev;
	cout << "Previos (in alphabetical order) " << (*prev).first << endl;
	cout << "Next (in alphabetical order) " << (*next).first << endl;

	int * intp = new int(5);
	if (intp){
		MyPointer p(intp);
		p.Add(5);
	}
	cout << *intp << endl;
	//april august december february  january july june march may november*/


	/* Start with the empty list */
	struct Node* res = NULL;
	struct Node* a = NULL;
	struct Node* b = NULL;

	/* Let us create two sorted linked lists to test
	the functions
	Created lists, a: 5->10->15,  b: 2->3->20 */
	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	/* Remove duplicates from linked list */
	res = SortedMerge(a, b);

	printf("Merged Linked List is: \n");
	printList(res);

	return 0;
}

