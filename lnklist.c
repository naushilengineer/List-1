#include<stdio.h>
#include<stdlib.h>

struct node{
char name[20];
int rollno;
float cgpa;
struct node* link;
};
struct node* newnode;
void display(struct node* head)
{
	if(head==NULL)
	{
	printf("The linked list is empty!!\n");
	}

	else
	{
	struct node* newnode;
	newnode=head;
	int count=1;
		while(newnode!=NULL)
		{
		printf("%d\n",count);
		printf("%s\n",newnode->name);
		printf("%d\n",newnode->rollno);
		printf("%f\n\n",newnode->cgpa);
		newnode=newnode->link;
		count=count+1;
		}
	}

}

void searchrollnno(struct node* head , int r)
{
if(head==NULL)
	{
	printf("The linked list is empty\n");
	}

	else
	{
	struct node* newnode;
	newnode=head;

		while(newnode->rollno!=r && newnode!=NULL)
		{
		newnode=newnode->link;
		}
		if(newnode!=NULL)
		{
		printf("The Record is = >>\n");
		printf("%s\n",newnode->name);
		printf("%d\n",newnode->rollno);
		printf("%f\n\n",newnode->cgpa);
		}
		else
		printf("Node not found\n");
	}

}


void searchname(struct node* head, char* s)
{
if(head==NULL)
{
printf("The record not found\n");
}

else if(head->link==NULL)
{
int i,co=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(head->name[i]!=s[i])
		{
		printf("The Record is not found\n");
		co=1;
		break;
		}

	}
if(co==0)
printf("Record found at node number 1\n");

}

else
{
newnode=head;
int no=0;
while(newnode!=NULL)
{
int i,co=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(newnode->name[i]!=s[i])
		{
		co=1;
		break;
		}

	}
if(co==1)
{
newnode=newnode->link;
no++;
}
else
{
printf("Record at node number %d \n",no+1);
break;
}
}

}

}

void searchcgpa(struct node* head,float p){
if(head==NULL)
{
printf("The record not found\n");
}

else if(head->link==NULL)
{
	if(head->cgpa!=p)
	{
	printf("The record not found\n");
	}
	else
	printf("Record at node number 1\n");

}

else{
int co=0,no=0;
newnode=head;
while(newnode!=NULL)
{
	if(newnode->cgpa==p)
	{
	printf("Record at node number %d \n",no+1);
	co++;
	break;
	}
	else
	{
	newnode=newnode->link;
	no++;
	}
}
if(co==0)
printf("record not found\n");

}
}

struct node* insertatend(struct node* head)
{

struct node* new=(struct node* )malloc(sizeof(struct node));
printf("Enter the name of the student:- ");
scanf("%s",new->name);
printf("Enter the roll no. of the student:-");
scanf("%d",&(new->rollno));
printf("Enter the cgpa of the student:-");
scanf("%f",&(new->cgpa));

new->link=NULL;
if(head==NULL)
{
	head=new;
}

else
{
	struct node* newnode;
	newnode=head;
	while(newnode->link!=NULL)
	{
	newnode=newnode->link;
	}
	newnode->link=new;
}
return head;
}


struct node* insertatfront(struct node* head)
{
struct node* new=(struct node* )malloc(sizeof(struct node));
printf("Enter the name of the student:- ");
scanf("%s",(new->name));
printf("Enter the roll no. of the student:-");
scanf("%d",&(new->rollno));
printf("Enter the cgpa of the student:-");
scanf("%f",&(new->cgpa));
new->link=NULL;

	if(head==NULL)
	{
	head=new;
	}

	else
	{
	new->link=head;
	head=new;

	}
return head;
}

struct node* insertinbetween(struct node* head)
{
int count=0,c;
struct node* new=(struct node* )malloc(sizeof(struct node));
printf("Enter the name of the student:- ");
scanf("%s",(new->name));
printf("Enter the roll no. of the student:-");
scanf("%d",&(new->rollno));
printf("Enter the cgpa of the student:-");
scanf("%f",&(new->cgpa));
new->link=NULL;
struct node* newnode;
struct node* newnode1;
printf("Enter the node where you want to add a new node:- ");
scanf("%d",&c);
	if(head==NULL)
	{
	printf("The linked list is empty");
	}

	else
	{
	newnode=head;
	count=1;
	while(count!=c && newnode!=NULL)
	{
	newnode=newnode->link;
	count++;
	}
	if(newnode==NULL)
	printf("Node not found");
	else
	{
	newnode1=newnode->link;
	newnode->link=new;
	new->link=newnode1;

	}
	}
return head;
}



struct node* deleteatfront(struct node* head)
{
	if(head==NULL)
	{
	printf("the linked list is empty\n");

	}

	else if(head->link==NULL)
	{
	head=NULL;
	}

	else
	{
	struct node* newnode;
	newnode=head->link;
	head=newnode;
	}
return head;
}

struct node* deleteinbetween(struct node* head , int pos)
{
if(head==NULL)
printf("The linked list is empty!!\n");

else if(pos==1 && head->link==NULL)
{
return NULL;
}
else
{
if(pos==1)
{
	return head->link;
}
else
{
	newnode=head;
	int count=1;
	while(count+1!=pos)
	{
	newnode=newnode->link;
	count++;
	}

	newnode->link=(newnode->link)->link;
}
}
return head;
}

struct node* deleteatend(struct node* head)
{
	if(head==NULL)
	{
	printf("the linked list is empty\n");
	}

	else if(head->link==NULL)
	{
	head=NULL;
	}

	else
	{
	struct node* newnode;
	newnode=head;
	while((newnode->link)->link!=NULL)
	{
	newnode=newnode->link;
	}
	newnode->link=NULL;
	}
return head;
}


void main()
{
struct node* head=NULL;
int ch,y=1,r;
float cg;
char s1[20];
do
{
printf("1.Insert in the front \n");
printf("2.Insert at the end \n");
printf("3.Insert between nodes \n");
printf("4.Delete an element from the front \n");
printf("5.Delete an element from the end \n");
printf("6.Delete an element from inbetween node.\n");
printf("7.Display the linked list\n");


printf("8.Search for a record by Rollno.\n");
printf("9.Search for a record by Name.\n");
printf("10.Search for a record by CGPA.\n");


printf("Enter your choice : -");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	head=insertatfront(head);
	break;

	case 2:
	head=insertatend(head);
	break;

	case 3:
	head=insertinbetween(head);
	break;

	case 4:
	head=deleteatfront(head);
	break;

	case 5:
	head=deleteatend(head);
	break;

	case 7:
	display(head);
	break;

	case 8:
	printf("enter the roll no. you want the search:-");
	scanf("%d",&r);
	searchrollnno(head,r);
	break;

	case 6:
	printf("please enter the position of the node you want to delete:-");
	scanf("%d",&r);
	head=deleteinbetween(head,r);
	break;

	case 9:
	printf("enter the Name you want the search:-");
	scanf("%s",&s1);
	searchname(head,s1);
	break;

	case 10:
	printf("enter the CGPA you want the search:-");
	scanf("%f",&cg);
	searchcgpa(head,cg);
	break;
  case 11:
	break;
	default:
	printf("wrong choice\n");
}
}while(ch!=11);


return 0;
}
