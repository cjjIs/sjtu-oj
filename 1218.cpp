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
	BinarySearchTree()
	{
		root = NULL;
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

	void preOrder(node *n)
	{
		cout<<n->data<<' ';
		if (n->left!=NULL)
			preOrder(n->left);
		if (n->right!=NULL)
			preOrder(n->right);
	}

	void show()//前序遍历
	{
		if(root == NULL)
		{
			cout<<endl;
			return;
		}
		preOrder(root);
	}


	void clear(node *&t)
	{

		if(t == NULL)return;
		clear(t->left);
		clear(t->right);
		delete t;
		t = NULL;
	}
	void clear()
	{
		clear(root);
	}
};




int main()
{
	int n,m,t,input[100];
	int output[120],t1=0;int i=0;
	char order;
	BinarySearchTree tree;
	cin>>n;
	while(n>0)
	{
		n--;
		cin>>order;cin>>m;
		if(m==0)
			continue;
		switch(order)
		{
			case '+':
			{
				t = 0;
				while(t<m)
				{
					cin>>input[t];
					tree.insert(input[t]);
					t++;
				}
				tree.show();
				break;
			}
			case '-':
			{
				t = 0;
				while(t<m)
				{
					cin>>input[t];
					tree.remove(input[t]);
					t++;
				}
				tree.show();
				break;
			}
			case '*':
			{
				t = 0;
				while(t<m)
				{
					cin>>input[t];
					if(tree.find(input[t]))
					{
						output[t1]=input[t];
						t1++;
					}
					t++;
				}
				tree.clear();
				for(i=0;i<t1;i++)
				{
					tree.insert(output[i]);
				}
				tree.show();
				break;
			}

		}

	}

	return 0;
}