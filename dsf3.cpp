#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *left,*right;
}root;
class tree
{
	root *nw;
	int key;
	
	public:
	void insert(root *, root *);
	void inorder( root*);
	void preorder(root*);
	void postorder(root*);
	
};
void tree:: insert ( root *root1,root * nw1)
{
	if(nw1->data >root1->data)
	{
		if(root1->right==NULL)
			root1->right=nw1;
		else
		insert(root1->right,nw1);
	}
	else
	{
		if(root1->left==NULL)
			root1->left=nw1;
		else
			insert(root1->left,nw1);
	}
}
void tree::inorder(root *nw1)
{
	if(nw1 !=NULL)
	{
		inorder(nw1->left);
		cout<<nw1->data<<" ";
		inorder(nw1->right);
	}
}
void tree::preorder(root *nw1)
{
	if(nw1 !=NULL)
	{
		cout<<nw1->data<<"   ";
		preorder(nw1->left);
		preorder(nw1->right);
	}
}
void tree::postorder(root *nw1)
{
	if(nw1 !=NULL)
	{
		postorder(nw1->left);
		postorder(nw1->right);
		cout<<nw1->data<<" ";
	}
}

int main()
{
	root *nw1,*root1=NULL,*nw;
	tree t;
	int data1,a,b,c;
	do
	{
		cout<<"\n 1.insert data :\n 2.inorder data \n 3. preorder data \n 4. postorder data";
		
		cout<<"\n enter your choice :";
		cin>>a;
		
		switch(a)
		{
			case 1:
				do
				{
					nw1= new root();
					cout<<"\n enter the data  : ";
					cin>>data1;
					nw1->data=data1;
					nw1->right=NULL;
					nw1->left=NULL;
					if(root1==NULL)
					{
						root1=nw1;
					}
					else
					{
						t.insert(root1,nw1);
					}
					cout<<"\n add more data? if yes then press 1 : ";
					cin>>b;
					
				}while(b==1);
				break;
			case 2:
				t.inorder(root1);
				break;
			case 3:
				t.preorder(root1);
				break;
			case 4:
				t.postorder(root1);
				break;
		}
		cout<<"\n do you want to continue if yes then press 1 : ";
		cin>>c;
	}while(c==1);
	
	return 0;
}


