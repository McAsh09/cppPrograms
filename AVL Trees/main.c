#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *l,*r;
	int h;
}node;

node *insert(node *,int);
node *delete(node *,int);
void preorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int b(node *);

int main()
{
	node *root=NULL;
	int x,n,i,ch;

	do
	{
		printf("\n1)Create:");
		printf("\n2)Insert:");
		printf("\n3)Delete:");
		printf("\n4)Print:");
		printf("\n5)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;

			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;

			case 3: printf("\nEnter a data to delete:");
					scanf("%d",&x);
					root=delete(root,x);
					break;

			case 4:   printf("\n\npreorder sequence:\n");
					    preorder(root);
					    printf("\n");
					     break;
		}
	}while(ch!=5);

	return 0;
}

node * insert(node *p,int x)
{
	if(p==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->data=x;
		p->l=NULL;
		p->r=NULL;
	}
	else
		if(x > p->data)
		{
			p->r=insert(p->r,x);
			if(b(p)==-2)
				if(x>p->r->data)
					p=RR(p);
				else
					p=RL(p);
		}
		else
			if(x<p->data)
			{
				p->l=insert(p->l,x);
				if(b(p)==2)
					if(x < p->l->data)
						p=LL(p);
					else
						p=LR(p);
			}

		p->h=height(p);

		return(p);
}

node * delete(node *p,int x)
{
	node *temp;

	if(p==NULL)
	{
		return NULL;
	}
	else
		if(x > p->data)
		{
			p->r=delete(p->r,x);
			if(b(p)==2)
				if(b(p->l)>=0)
					p=LL(p);
				else
					p=LR(p);
		}
		else
			if(x<p->data)
			{
				p->l=delete(p->l,x);
				if(b(p)==-2)
					if(b(p->r)<=0)
						p=RR(p);
					else
						p=RL(p);
			}
			else
			{
				if(p->r!=NULL)
				{
					temp=p->r;

					while(temp->l!= NULL)
						temp=temp->l;

					p->data=temp->data;
					p->r=delete(p->r,temp->data);

					if(b(p)==2)
						if(b(p->l)>=0)
							p=LL(p);
						else
							p=LR(p);
				}
				else
					return(p->l);
			}
	p->h=height(p);
	return(p);
}

int height(node *p)
{
	int lh,rh;
	if(p==NULL)
		return(0);

	if(p->l==NULL)
		lh=0;
	else
		lh=1+p->l->h;

	if(p->r==NULL)
		rh=0;
	else
		rh=1+p->r->h;

	if(lh>rh)
		return(lh);

	return(rh);
}

node * rotateright(node *x)
{
	node *y;
	y=x->l;
	x->l=y->r;
	y->r=x;
	x->h=height(x);
	y->h=height(y);
	return(y);
}

node * rotateleft(node *x)
{
	node *y;
	y=x->r;
	x->r=y->l;
	y->l=x;
	x->h=height(x);
	y->h=height(y);

	return(y);
}

node * RR(node *p)
{
	p=rotateleft(p);
	return(p);
}

node * LL(node *p)
{
	p=rotateright(p);
	return(p);
}

node * LR(node *p)
{
	p->l=rotateleft(p->l);
	p=rotateright(p);

	return(p);
}

node * RL(node *p)
{
	p->r=rotateright(p->r);
	p=rotateleft(p);
	return(p);
}

int b(node *p)
{
	int lh,rh;
	if(p==NULL)
		return(0);

	if(p->l==NULL)
		lh=0;
	else
		lh=1+p->l->h;

	if(p->r==NULL)
		rh=0;
	else
		rh=1+p->r->h;

	return(lh-rh);
}

void preorder(node *p)
{
	if(p!=NULL)
	{
	    printf("%d(b=%d)",p->data,b(p));
	    preorder(p->l);
	    preorder(p->r);


	}
}
