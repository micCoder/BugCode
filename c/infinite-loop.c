#include <stdio.h>

typedef struct Node_
{
	int cnt;
	struct Node_ *next;
}Node;

typedef struct List_
{
	Node *head;
}List;

void func(void)
{
	List list;
	Node node;
	
	/* The next pointer has been initialized to NULL */ 
	node.cnt = 0;
	node.next = NULL;
	
	/* Only one node in list */
	list.head = &node;
	
	/* Bug code: infinite loop*/
	Node *pnode = list.head;
	int cnt = pnode->cnt;
	while (pnode != NULL) {
		printf("hello while\n");
		pnode = pnode->next;
		if (cnt < pnode->cnt) {
			cnt = pnode->cnt;
		}
	}
}

int main(int argc, char **argv)
{
	func();
	return 0;
}

/*
If compiled with GCC's -02 option, the while statement in the func function will loop indefinitely. 
Otherwise, the program will core dumped
*/
