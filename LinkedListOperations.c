#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);
struct node *add_at_begin(struct node *);
struct node *add_at_end(struct node *);
struct node *insert_before(struct node*);
struct node *insert_after(struct node*);
struct node *delete_begining(struct node*);
struct node *delete_end(struct node*);
struct node *delete_before_loc(struct node*);
struct node *delete_after_loc(struct node*);
struct node *sort_list(struct node *);
struct node *add_in_sorted_list(struct node*);
struct node *reverse_list(struct node *);
int len(int);
int main()
{
int ch;
int a,length;
do
{
printf("enter\n 1.create linked list\n");
printf("2.display linked list\n");
printf("3.for finding the length of linked list\n");
printf("4.add at begin in linked list\n");
printf("5.add at end in linked list\n");
printf("6.insert before the given loaction in linked list\n");
printf("7.insert after the given loaction in linked list\n");
printf("8.for deleting the first node of linked list\n");
printf("9.for deleting the last node of linked list\n");
printf("10.deleting the node  before given location\n");
printf("11.deleting the node  after given location\n");
printf("12.for sorting the linekd list\n");
printf("13.adding a node in sorted list\n");
printf("14.for reversing the list\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:start=create_ll(start);
       printf("linked list has been created\n");
       break;
case 2:start=display_ll(start);
       break;
case 3:length=len(a);
       printf("length of linked list is %d\n",length);
       break;
case 4:start=add_at_begin(start);
       break;
case 5:start=add_at_end(start);
       break;
case 6:start=insert_before(start);
       break;
case 7:start=insert_after(start);
       break;
case 8:start=delete_begining(start);
       break;
case 9:start=delete_end(start);
       break;
case 10:start=delete_before_loc(start);
       break;
case 11:start=delete_after_loc(start);
       break;
case 12:start=sort_list(start);
       break;
case 13:start=add_in_sorted_list(start);
       break;
case 14:start=reverse_list(start);
        break;
}
}
while(ch!=-1);
return 0;
}
struct node *create_ll(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end\n");
printf("\n Enter the data : ");
scanf("%d", &num);
while(num!=-1)
{		
new_node=(struct node*)malloc(sizeof(struct node));		
new_node->data=num;
if(start==NULL)
{			
new_node -> next = NULL;
start = new_node;
}
else
{
ptr=start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next = new_node;
new_node->next=NULL;
}		
printf("\n Enter the data : ");
scanf("%d", &num);
}
return start;
}
struct node *display_ll(struct node *start)
{
struct node *ptr;
printf("linked list has been displayed\n");
ptr=start;
if(ptr==NULL)
{
printf("linked list is empty\n");
}
while(ptr!=NULL)
{
printf("%d->\t",ptr->data);
ptr=ptr->next;
}
printf("\n");
return start;
}
int len(int x)
{
int count=0;
struct node *ptr;
ptr=start;
if(start==NULL)
{
printf("linked list is empty\n");
}
else
{
while(ptr!=NULL)
{
count++;
ptr=ptr->next;
}
}
return count;
}
struct node *add_at_begin(struct node *start)
{
struct node *new_node;
int num;
printf("\n Enter the data should be addaed at the begin\n");
scanf("%d", &num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
new_node -> next = start;
start = new_node;
printf("Data inserted succesfully\n");
return start;
}
struct node *add_at_end(struct node *start)
{
struct node *ptr,*new_node;
int data;
printf("enter the data should be added at the end\n");
scanf("%d",&data);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=data;
ptr=start;
if(start==NULL)
{
new_node->next=NULL;
start=new_node;
}
else
{
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=NULL;
}
return start;
}
struct node *insert_before(struct node *start)
{
struct node *ptr,*preptr,*new_node;
int data,loc;
printf("enter the location\n");
scanf("%d",&loc);
printf("enter the data should be addaed\n");
scanf("%d",&data);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=data;
ptr=start;
preptr=start;
if(start==NULL)
{
new_node->next=NULL;
start=new_node;
}
else
{
while(ptr->data!=loc)
{
preptr=ptr;
ptr=ptr->next;
}
new_node->next=ptr;
preptr->next=new_node;
}
return start;
}
struct node *insert_after(struct node *start)
{
struct node *ptr,*new_node;
int data,loc;
printf("enter the location\n");
scanf("%d",&loc);
printf("enter the data should be addaed\n");
scanf("%d",&data);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=data;
ptr=start;
if(start==NULL)
{
new_node->next=NULL;
start=new_node;
}
else
{
while(ptr->data!=loc)
{
ptr=ptr->next;
}
new_node->next=ptr->next;
ptr->next=new_node;
}
return start;
}
struct node *delete_begining(struct node *start)
{
struct node *ptr;
ptr=start;
if(start==NULL)
{
printf("linked list is in underflow\n");
}
else
{
start=start->next;
free(ptr);
}
return start;
}
struct node *delete_end(struct node *start)
{
struct node *ptr,*preptr;
ptr=start;
preptr=start;
if(start==NULL)
{
printf("linked list is in underflow\n");
}
else
{
while(ptr->next!=NULL)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=NULL;
free(ptr);
}
return start;
}
struct node *delete_before_loc(struct node *start)
{
struct node *ptr,*preptr;
int loc;
printf("enter the location\n");
scanf("%d",&loc);
ptr=start;
preptr=start;
if(start==NULL)
{
printf("linked list is in underflow\n");
}
else
{
while(ptr->data!=loc)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=ptr->next;
free(ptr);
}
return start;
}
struct node *delete_after_loc(struct node *start)
{
struct node *ptr,*preptr;
int loc;
printf("enter the location\n");
scanf("%d",&loc);
ptr=start;
preptr=start;
if(start==NULL)
{
printf("linked list is in underflow\n");
}
else
{
while(ptr->data!=loc)
{
preptr=ptr;
ptr=ptr->next;
}
ptr=ptr->next;
preptr=preptr->next;
preptr->next=ptr->next;
free(ptr);
}
return start;
}
struct node *sort_list(struct node *start)
{
struct node *ptr1,*ptr2;
int temp;
ptr1=start;
if(start==NULL)
{
printf("linked list is in underflow\n");
}
else
{
while(ptr1->next!=NULL)
{
ptr2=ptr1->next;
while(ptr2!=NULL)
{
if(ptr1->data>ptr2->data)
{
temp=ptr1->data;
ptr1->data=ptr2->data;
ptr2->data=temp;
}
ptr2=ptr2->next;
}
ptr1=ptr1->next;
}
}
return start;
}
struct node *add_in_sorted_list(struct node *start)
{
struct node *ptr,*preptr,*new_node;
int data;
printf("enter the data sholud be added in the list\n");
scanf("%d",&data);
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=data;
ptr=start;
if(start==NULL)
{
new_node->next=NULL;
start=new_node;
}
else
{
while(ptr->data<data)
{
preptr=ptr;
ptr=ptr->next;
}
new_node->next=preptr->next;
preptr->next=new_node;
}
return start;
}
struct node *reverse_list(struct node *start)
{
struct node *ptr1,*ptr2;
int i=0,j,a,temp,k;
j=len(a)-1;
ptr1=start;
ptr2=start;
if(start==NULL)
{
printf("linked list is in underflow\n");
}
else
{
while(i<j)
{
k=0;
while(k<j)
{
ptr1=ptr1->next;
k++;
}
temp=ptr1->data;
ptr1->data=ptr2->data;
ptr2->data=temp;
i++;
j--;
ptr2=ptr2->next;
ptr1=start;
}
}
return start;
}

