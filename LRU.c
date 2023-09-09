#include <stdio.h>
#include<stdlib.h>
#define TRUE     1
#define FALSE    0
#define OK       1
#define ERROR    0
#define INFEASIBLE -1
#define OVERFLOW -2
#define pf(a)  printf("%d\n",a);
#define LIST_INIT_SIZE 100           
#define LISTINCREMENT 10           
#define SIZE 10
/*
* Define a single list struct
*/
typedef struct Node				 
{
	int elem;
	struct Node* next;
} Node;
typedef Node* LinkList;			
/*
* Create the head node
*/
LinkList CreateLinkList(void)
{
	LinkList head = (struct Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		printf("³õÊ¼»¯Ê§°Ü");
		exit(0);		 
	}
	head->next = NULL;
	return head;
}							 
/*
* print the list from head(you should input address)
*/
void PrintList(LinkList  head)		 
{
	LinkList pmove = head->next;
	while (pmove != NULL)
	{
		printf("%d\n", pmove->elem);
		pmove = pmove->next;
	}
	printf("NULL\n");
}
/*
* Auto increase the new node from tail
*/
void AddNode(LinkList list, int data)		
{
	LinkList p = list;
	while (p->next != NULL) {
		p = p->next;
	}
	LinkList newNode = (struct Node*)malloc(sizeof(Node));
	newNode->elem = data;
	newNode->next = NULL;
	p->next = newNode;
}

/*creat new node*/
LinkList CreateNode(int data)		
{
	LinkList newnode = (struct Node*)malloc(sizeof(Node));
	newnode->elem = data;
	newnode->next = NULL;
	return newnode;
}
/*
* Insert node from specific position
*/
void put(LinkList head, int data, int pos)		 
{
	LinkList newnode = CreateNode(data);
	LinkList p = head;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}
	newnode->next = p->next;
	p->next = newnode;
}
/*
* delet the specific node
*/
void DeletNode(LinkList head, int pos)						 
{
	LinkList p = CreateLinkList();
	LinkList q;
	p = head;
	for (int i = 0; p->next && i < pos - 1; i++)
	{
		p = p->next;
	}
	q = p->next;
	p->next = q->next;
	free(q);
}
/*
* search specific node
*/
void get(LinkList head, int data)					 
{
	LinkList pmove = head;
	if (pmove == NULL)
		{
			printf("No,we can't find it ,sorry!!!qwq");
			exit(0);
		}
	for (int i = 0; pmove != NULL; i++)
	{
		if (pmove->elem == data)
		{
			printf("This data is in position %d\n", i);
			
		}
		pmove = pmove->next;
	}
	
}

int main()
{
	int w,elem;
	int i = 0;
	int length = SIZE;
	int count = 0;
	int pos, oldnodepos = 0;

	/*create the head noed*/
	LinkList LRUhead = CreateLinkList();
	for (int i = 0; i < length; i++)
	{
		int elem = (i + 1);
		AddNode(LRUhead, elem);
	}
	PrintList(LRUhead);
	
	/*Insert node operation*/
	while (1)
	{
		pos = count % length;
		printf("Whether add elem? \n");
		printf(" If you want to do,input 1 here.\n");
		printf(" If you don't want to do,input 0 here.\n");
		scanf_s("%d",&w);

		

		if (w == 0) goto again;
		if (w==1)
		{
			int addelem;
			
			printf("Please input the elem that you want to put in list:");
			scanf_s("%d",&addelem);
			/*Checking for duplicate elements in an array*/
			LinkList pmove = LRUhead;
			for (int i = 0; pmove != NULL; i++)
			{
				if (pmove->elem == addelem)
				{
					elem = addelem;
					goto here;
				}
				pmove = pmove->next;
			}


			put(LRUhead, addelem, pos+1);
			DeletNode(LRUhead, pos+2);
			count++;
		}
		PrintList(LRUhead);
	}
	again:
	/*Sreach node operation*/
	while (1)
	{
		pos = count % length;
		printf("Whether sreach node? \n");
		printf(" If you want to do,input 1 here.\n");
		printf(" If you don't want to do,input 0 here.\n");
		scanf_s("%d", &w);

		if (w == 1)
		{
			int oldnodepos;
			printf("Please input the elem that you want to get in list:");
			scanf_s("%d", &elem);

			/*sreach node*/
			LinkList pmove = LRUhead;
			while (pmove != NULL)
			{
				if (pmove->elem == elem)
				{
					printf("This data is in position %d\n", i);
					goto here;
				}
				pmove = pmove->next;
				oldnodepos = i;
				i++;

			}
			if (pmove == NULL)
			{
				printf("No,we can't find it ,sorry!!!qwq");
				exit(0);
			}
			here:
			put(LRUhead, elem, pos + 1);
			DeletNode(LRUhead, oldnodepos+2);
			count++;
		}
		PrintList(LRUhead);
		if (w == 0) return 0;
	}

	return 0;
}