#include <iostream>

using namespace std;

class BinarySearchTree
{
private:
	struct node//
	{
		int data;
		node *left,*right;
		node(int d,node *l=NULL,node *r=NULL){data=d;left=l;right=r;}
		~node(){}
	};

	node *root;

public:
	BinarySearchTree(int d)
	{
		root=new node(d);
	}

	void insert(node *&r,int d)
	{
		if(r == NULL)
		{
			r = new node(d);
			return;
		}
		if (r->data>=d)
			insert(r->left,d);
		else
			insert(r->right,d);
	}//插入函数

	void insert(int d)
	{
		insert(root,d);
	}

	void remove(node *&r,int d)
	{
		if (r==NULL)
			return ;
		if (r->data>d)
			remove(r->left,d);
		else if (r->data<d)
			remove(r->right,d);
		else
		{
			if (r->left==NULL || r->right==NULL)
				r=(r->left == NULL)? r->right : r->left ;
			else
			{
				node *tmp=r;
				tmp=tmp->right;
				while (tmp->left!=NULL)
					tmp=tmp->left;
				r->data=tmp->data;
				remove(r->right,tmp->data);
			}
		}
	}

	void remove(int d)
	{
		remove(root,d);
	}

	bool find(node *r,int d)
	{
		if (r==NULL)
			return false;
		if (r->data==d)
			return true;
		else if (r->data>d)
			return find(r->left,d);
		else 
			return find(r->right,d);
	}

	bool find(int d)
	{
		return find(root,d);
	}
};

int main()
{
	return 0;
}