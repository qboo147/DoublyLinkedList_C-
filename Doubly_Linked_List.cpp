#include<iostream>
using namespace std;
#define ElementType Product

typedef struct Product
{
	string name;
	string producer;
	string ID;
};

typedef struct Node
{
	ElementType info;
	struct Node* next;
	struct Node* prev;
};

typedef struct LinkedList
{
	Node* Head;
	Node* Tail;
};

void InitList(LinkedList& List);
Node* CreateNode(ElementType x);
bool IsEmptyList(LinkedList List);
void AddFirst(LinkedList& List, Node* p);
void AddLast(LinkedList& List, Node* p);
void Insert(LinkedList& List, Node* p, Node* q);
void RemoveFirst(LinkedList& List);
void RemoveLast(LinkedList& List);
void Remove(LinkedList& List, Node* p);
int SearchNode(LinkedList List, Node* p);
void Print(LinkedList List);
void SelectionSort(LinkedList& List);
void QuickSort(LinkedList& List);

int main()
{


	return 0;
}

void Out(Node* p)
{
	cout << "-------------------" << endl;
	cout << "Name: " << p->info.name << endl;
	cout << "Producer: " << p->info.producer << endl;
	cout << "ID: " << p->info.ID << endl;
	cout << "-------------------" << endl;
}

void Print(LinkedList List)
{
	Node* p = List.Head;
	while (p != NULL)
	{
		Out(p);
		p = p->next;
	}
}

int SearchNode(LinkedList List, Node* p)
{
	Node* q = List.Head;
	while (q != NULL)
	{
		if (q->info.ID == p->info.ID)
		{
			return 1;
		}
		q = q->next;
	}
	return 0;
}

void Remove(LinkedList& List, Node* p)
{
	if (IsEmptyList(List) || p == NULL)
	{
		cout << "Khong thuc hien duoc" << endl;
	}
	else
	{
		Node* q = p;
		if (List.Head == List.Tail)
		{
			List.Head = List.Tail = NULL;
		}
		else
		{
			p->next = p->next->next;
			p->next->prev = p;
		}
		delete q;
	}
}

void RemoveLast(LinkedList& List)
{
	if (IsEmptyList(List))
	{
		cout << "Danh sach rong" << endl;
	}
	else
	{
		Node* p = List.Tail;
		if (List.Head == List.Tail)
		{
			List.Head = List.Tail = NULL;
		}
		else
		{
			List.Tail = List.Tail->prev;
			List.Tail->next = NULL;
		}
		delete p;
	}
}

void RemoveFirst(LinkedList& List)
{
	if (IsEmptyList(List))
	{
		cout << "Danh sach rong" << endl;
	}
	else
	{
		Node* p = List.Head;
		if (List.Head == List.Tail)
		{
			List.Head = List.Tail = NULL;
		}
		else
		{
			List.Head = List.Head->next;
			List.Head->prev = NULL;
		}
		delete p;
	}
}

void Insert(LinkedList& List, Node* p, Node* q)
{
	if (IsEmptyList(List) || q == NULL)
	{
		cout << "Khong the thuc hien" << endl;
	}
	else
	{
		p->next = q->next;
		p->prev = q;
		q->next = p;
		if (List.Tail == q)
		{
			List.Tail == p;
		}
		else
		{
			p->next->prev = p;
		}
	}
}

void AddLast(LinkedList& List, Node* p)
{
	if (IsEmptyList(List))
	{
		List.Head = List.Tail = p;
	}
	else
	{
		p->next = NULL;
		p->prev = List.Tail;
		List.Tail->next = p;
		List.Tail = p;
	}
}

void AddFirst(LinkedList& List, Node* p)
{
	if (IsEmptyList(List))
	{
		List.Head = List.Tail = p;
	}
	else
	{
		p->prev = NULL;
		p->next = List.Head;
		List.Head->prev = p;
		List.Head = p;
	}
}

bool IsEmptyList(LinkedList List)
{
	if (List.Head == NULL)
	{
		return true;
	}
	return false;
}

Node* CreateNode(ElementType x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "Khong du bo nho" << endl;
		return;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void InitList(LinkedList& List)
{
	List.Head = List.Tail = NULL;
}