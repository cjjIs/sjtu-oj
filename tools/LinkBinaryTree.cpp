#include <iostream>

using namespace std;

template <class T>
class BinaryTree
{
private:
	struct node
	{
		node *left,*right;
		T data;
		node():left(NULL),right(NULL){}
		node(T item,node *L = NULL,node *R = NULL):data(item),left(L),right(R){}
	};
public:
	node *root;
	BinaryTree():root(NULL){}

	BinaryTree(const T &x){root = new node (x);}

	~BinaryTree(){clear();}

	void clear(){clear(root);root = NULL;}
	void clear(node *n)
	{
		if(n==NULL)return;
		if(n->left!=NULL)clear(n->left);
		if(n->right!=NULL)clear(n->right);
		delete n;
	}

	void delLeft(){delLeft(root);}	
	void delLeft(node *n)
	{
		clear(n->left);
		n->left = NULL;
	}

	void delright(){delright(root);}
	void delright(node *n)
	{
		clear(n->right);
		n->right = NULL;
	}

	bool isEmpty(){return root = NULL;}
	
	int size(){return size(root);}
	int size(node *n)
	{
		if(t==NULL)return 0;
		return 1+size(t->left)+size(t->right);
	}

	int height(){return height(root);}
	int height(node *n)
	{
		if(t==NULL)return 0;
		int lt = height(t->left),rt = height(t->right);
		return 1+((lt>rt)?lt:rt);
	}

	void perOrder()
	{
		if(root==NULL)return;
		perOrder(root);
	}
	void perOrder(node *n)
	{
		if(n==NULL)return;
		cout<<n->data<<' ';
		perOrder(n->left);
		perOrder(n->right);
	}

	void postOrder()
	{
		if(root == NULL)return;
		postOrder(root);
	}
	void postOrder(node *n)
	{
		if(n==NULL)return;
		postOrder(n->left);
		postOrder(n->right);
		cout<<n->data<<' ';
	}

	void midOrder()
	{
		if(root==NULL)return;
		midOrder(root);
	}
	void midOrder(node *n)
	{
		if(n==NULL)return;
		midOrder(n->left);
		cout<<n->data<<' ';
		midOrder(n->right);
	}

	
};