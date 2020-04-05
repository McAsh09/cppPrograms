#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;

struct stack
{
    int size;
    int top;
    struct node **s;
};

void stackcreate(struct stack *st,int size)

{
    st->size=size;
    st->top=-1;
    st->s=(struct node **)malloc((st->size)*sizeof(struct node*));
}

void Push(struct stack *st,struct node *x)
{
    if(st->top==st->size-1)
    printf("STACK OVERFLOW");
    else
        {
            st->top++;
            st->s[st->top]=x;
        }
}

struct node *pop(struct stack *st)
{
    struct node *x=NULL;
    if(st->top==-1)
    printf("STACK UNDERFLOW\n");
    else
    {
        x=st->s[st->top--];

    }

return x;

}

int isemp(struct stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}

int isfull(struct stack st)
{
    return st.top==st.size-1;
}

struct node *push(struct node *troot,int data)
{
    if(troot==NULL)
    {
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        if(root==NULL)
        root=temp;

return temp;
    }

else
    if(data>(troot->data))
    {
            troot->right=push(troot->right,data);
    }
else

    if(data<(troot->data))
    troot->left=push(troot->left,data);

return troot;
}

struct node *find_max(struct node *temp)
{
    if(temp->right==NULL)
    return temp;
    else
    find_max(temp->right);
}

struct node *find_min(struct node *temp)
{
    if(temp->left==NULL)
    return temp;
    else
    find_min(temp->left);
}

int countln(struct node *p)
{

    int x,y;
    if(p!=NULL)
    {
        x=countln(p->left);
        y=countln(p->right);
        if(p->left==NULL&&p->right==NULL)
        return x+y+1;
    else
    return x+y;
    }

return 0;
}

int height(struct node *p)

{
    int x,y;
    if(p==NULL)
    return 0;
    x=height(p->left);
    y=height(p->right);
    return x>y?x+1:y+1;
}

int preorder(struct node *temp)
{
    if(temp==NULL)
    return 0;
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
    return 0;
}

int postorder(struct node *temp)
{

    if(temp==NULL)
    return 0;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
    return 0;
}

struct node *delete_node(struct node *temp,int key)
{
    if(temp->data==key)
    {
        if(temp->left==NULL)
        {
            struct node *tright=temp->right;
                if(temp==root)
                {
                    root=temp->right;
                }
        free(temp);
        return tright;
        }
else

if(temp->right==NULL)
    {
        struct node *tleft=temp->left;
            if(temp==root)
            {
                root=temp->left;
            }

    free(temp);
    return tleft;
    }
else

    if(temp->right!=NULL && temp->left!=NULL)
        {
            temp->data=find_max(temp->left)->data;
            temp->left=delete_node(temp->left,find_max(temp->left)->data);
            return temp;
        }
    }
else

if(key>temp->data)
{
    temp->right=delete_node(temp->right,key);
}
else

    if(key<temp->data)
    {
        temp->left=delete_node(temp->left,key);
    }
return temp;
}

void iterativeinorder(struct node *p)
{
    struct stack stk;
    stackcreate(&stk,100);
    while(p || !isemp(stk))
    {
        if(p)
        {
            Push(&stk,p);
            p=p->left;
        }
else
{
    p=pop(&stk);
    printf("%d ",p->data);
    p=p->right;
}
    }
}

int main()
{
    int choice,key,count=0;
    int data;
    while(1)
    {
        printf("\nWHAT DO YOU WANT ? \n1.ADD DATA(CREATE/INSERT)\n2.DISPLAY(POSTORDER)\n3.DELETE\n4.HEIGHT\n5.PREORDER\n6.COUNT NODES\n7.INORDER(NON-RECURSIVE) ");
        printf("\nCHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nENTER DATA: ");
            scanf("%d",&data);
            count++;
            if(data!=-1)
            push(root,data);
            break;
            case 2:postorder(root);
            printf("\n");
            break;
            case 3:
            printf("\nENTER DATA TO DELETE: ");
            scanf("%d",&key);
            delete_node(root,key);
            break;
            case 4:printf("\nHEIGHT: %d\n",height(root));
            break;
            case 5:
            preorder(root);
            printf("\n");
            break;
            case 6:
            printf("\nNO. OF LEAF NODES :%d\n",countln(root));
            printf("\nNO. OF NON LEAF NODES :%d\n",count-countln(root));
            break;
            case 7:
            iterativeinorder(root);
            printf("\n");
            break;
        }
    }
return 0;
}
