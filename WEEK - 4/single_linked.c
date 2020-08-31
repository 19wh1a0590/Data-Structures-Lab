#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *head = NULL,*tail = NULL,*cur,*next,*prev;
void create()

{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%d",&(cur -> data));
		cur -> link = NULL;
		if(head == NULL)
			head = tail =cur;
		else
		{
			tail -> link = cur;
			tail = cur;
		}
		printf("\n");
	}


}
void display(){
    if(head == NULL)
        printf("List is empty");
    else{
        next = head;
            while(next!= NULL)
            {
                printf("%d->",next -> data);
                next = next -> link;
            }
    }
    }
void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
    printf("enter current node data\n");
	scanf("%d",&(cur -> data));
	cur -> link = head;
	head = cur;
}

void insert_at_end()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&(cur -> data));
	cur -> link = NULL;
	tail -> link = cur;
	tail = cur;
}

void insert_at_pos()
{
	int pos,c=1;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter data to be inserted\n");
	scanf("%d",&(cur -> data));
	printf("enter position\n");
    scanf("%d",&pos);
	next = head;
	while(c < pos)
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = cur;
	cur -> link = next;
}
void insert_before_node()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter \n");
    scanf("%d",&(cur -> data));   //new node
    printf("enter value\n");
	scanf("%d",&value);    //value before  ex 10,20,30,   .... so take 20
	next = head;
	while(next->data != value && next != NULL)
	{
		prev = next;
		next = next -> link;
	}
    prev -> link = cur;
    cur -> link = next;
	}

void insert_after_node()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter the node to be inserted ");
	scanf("%d",&(cur -> data));
	printf("enter the node");
	scanf("%d",&value);
	next = head;
	while(next -> data != value && next != NULL)
	{
		next = next -> link;
	}
	cur -> link = next -> link;
	next -> link = cur;
}

void delete_at_begin()
{
	cur = head;
	head = cur -> link;
	cur -> link = NULL;
	printf("Deleted element is %d\n",cur -> data);
	free(cur);
}
void delete_at_pos()
{
	int pos,c=1;
	printf("enter position of deletion");
	scanf("%d",&pos);
	next = head;
	while(c < pos)
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = next -> link;
	printf("deleted element is %d\n",next -> data);
	next -> link = NULL;
	free(next);
}
void delete_before_node()
{
    int value;
    printf("enter before which node we need to delete\n");
	scanf("%d",&value);
	next = head;
	while(next -> link -> data != value)
	{
		prev = next;
		next = next -> link;
	}
	prev -> link = next -> link;
	next -> link =NULL;
	printf("Deleted element is %d\n",next -> data);
	free(next);
}

void delete_after()
{
	int value;
	printf("enter after which node we  need to delete\n");
	scanf("%d",&value);
	next = head;
	while (next -> data != value)
	{
		prev = next;
		next = next -> link;
	}
	prev = next -> link;
	next -> link = prev -> link;
	printf("deleted data is %d\n",prev -> data);
	prev -> link = NULL;
	free(prev);
}
void delete_at_end()
{
    cur = head;
    while(cur -> link != tail)
        cur = cur -> link;
    cur -> link = NULL;
    next = tail;
    printf("deleted element is %d\n",next -> data);
    free(next);
    tail = cur;
}
void sorting()
{
	struct node*p1,*p2;
	p1 = head;
	int c=0,i,t;
	while(p1 != NULL)
	{
	    c++;
	    p1=p1->link;
	}
	for(i=0;i<c;i++)
    {
        p2=head;
        while(p2->link != NULL)
        {

            if(p2 -> data  > p2 -> link -> data)
			{
                t = p2 -> data;
                p2 -> data = p2 -> link -> data;
                p2 -> link -> data = t;
			}
            p2 = p2 -> link;
		}
	}
}
void reverse_sll()
{

    int a[100],i=0;
    cur=head;
    while(cur != NULL)
    {
        a[i++] = cur -> data;
        cur = cur->link;
    }
    i--;
    while(i >= 0)
    {

        printf("%d->",a[i]);
        i--;
    }
}
void search()

{
	int val,flag=0,c=0;
	printf("enter the value to be searched");
	scanf("%d",&val);
	next=head;
	while(next != NULL)
	{
		if(next ->data == val)
		{
			flag = 1;
			break;
		}
		next = next -> link;
		c++;
	}
	if (flag == 1)
	{
 		printf("element present in the list at %d position\n",c);
	}
	else
		printf("elements not present in the list\n");
}



int main()
{
	int ch;
	while(1)
	{
	printf("program for single linked list\n");
	printf("1-create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before node");
	printf("\n6-insert after\n7-delete at begin\n8-delete at end\n9-delete at pos\n10-delete before \n");
	printf("11-delete after\n12-display\n13-display in reverse\n14-search\n15-Sorting\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: create();
                break;
        case 12: display();
                break;
        case 2: insert_at_begin();
                break;
        case 4: insert_at_end();
                break;
        case 3: insert_at_pos();
                break;
        case 5: insert_before_node();
                break;
        case 6: insert_after_node();
                break;
        case 7: delete_at_begin();
                break;
        case 8: delete_at_end();
                break;
        case 9: delete_at_pos();
                break;
        case 10: delete_before_node();
                break;
        case 11: delete_after();
                break;
        case 15: sorting();
                break;
        case 14 : search();
                break;
        case 13: reverse_sll();
                break;
		case 16: exit(0);
	}
	}
	return 0;

}
