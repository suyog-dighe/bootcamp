#include<iostream>
using namespace std;

struct nodestack
    {
    int data;
    nodestack *next;
    };
class stack
    {
    public:
    nodestack *top;

    void createstack();
    void push(int);
    bool isEmpty();
    int pop();
    };

    void stack::createstack()
    {
    top=NULL;
    }
    void stack::push(int item)
    {
    nodestack *newnode;
    newnode=new(nodestack);
    if(newnode==NULL)
    cout<<"cannot allocate memory";
    newnode->data=item;
    newnode->next=top;
    top=newnode;
    }
    bool stack::isEmpty()
    {
    return(top==NULL);
    }
    int stack::pop()
    {
    nodestack *delnode;
    if(isEmpty())
    {
    int flag1=flag1+1;
    return 1;
    }
    else
    {
    delnode=top;
    top=delnode->next;
    delete(delnode);
    }
    return 0;
}
int main()
{
    char get[20];
    char ch;
    int i, flag=0;
    int flag1=0;
    cout<<"enter the parentesis:";
    cin>>get;
    stack x;
    x.createstack();
    for(i=0;get[i]!='\0';i++)
    {
    ch=get[i];
    if(ch=='(')
    x.push(ch);
    else
    if(ch==')')
    flag=x.pop();
    }
    if(x.isEmpty() and flag==0){
    if(flag1<1){
    cout<<"wellformess of parenthesis\n";
    }
    else
    {
    cout<<"not a well formedness of parenthesis";
    }
    }
    else{

    cout<<"not well formess of parenthesis\n";
    }
    return 0;
}
