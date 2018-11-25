#include <iostream>

#include <queue>
using namespace std;

template <class T>

class linkQueue
{
private:
	struct node
	{
		T data;
		node *next;
		node(){next = NULL;}
		node(const T &d,node *n=NULL){data=d;next=n;}
		~node(){};
	};

	node *front;
	node *rear;

public:
	linkQueue()
	{
		front=rear = NULL;
	}
	~linkQueue()
	{
		node *tmp;
		while(front!=NULL)
		{
			tmp = front;
			front = front->next;
			delete tmp;
		}
	}

	void enQueue(const T &d)
	{
		if (rear==NULL)
			front=rear=new node(d);
		else
		{
			rear->next=new node(d);
			rear=rear->next;
		}
	}

	T deQueue()
	{
		T t=front->data;
		node *tmp=front;
		front=front->next;
		if (front==NULL)
			rear=front;
		delete tmp;
		return t;
	}

	bool isEmpty(){return front==NULL;}
};

class binaryTree
{
public:
	struct node
	{
		int data;
		node *left;
		node *parent;
		node *right;
		node(int d=0,node *l=NULL,node *r=NULL,node *p=NULL)
		{data=d;left=l;right=r;parent=p;}
		~node(){};
	};

	node *root;
	node *nodes;

	binaryTree(){}
	~binaryTree(){delete []nodes;}


	void makeTree(int m)
	{
		int l,r,n;
		nodes = new node[m+1];
		for(int i = 0;i<m;i++)
		{
			cin>>l>>r>>n;
			nodes[i].data = n;
			if(l!=0)
			{
				nodes[i].left = &nodes[l-1];
				nodes[l-1].parent = &nodes[i];
			}
			if(r!=0)
			{
				nodes[i].right = &nodes[r-1];
				nodes[r-1].parent = &nodes[i];
			}
		}

		root = &nodes[0];
		while(root->parent!=NULL)
			root=root->parent;

		preOrder();
		cout<<endl;
		midOrder();
		cout<<endl;
		levelOrder();

	}

	void preOrder(node *n)
	{
		if(n==NULL)return;
   		cout<<n->data<<' ';
    	preOrder(n->left);
		preOrder(n->right);
	}

	void preOrder(){preOrder(root);}

	void midOrder(node *n)
	{
		if (n->left!=NULL)
			midOrder(n->left);
		cout<<n->data<<' ';
		if (n->right!=NULL)
			midOrder(n->right);
	}

	void midOrder(){midOrder(root);}

	void postOrder(node *n)
	{
		if(n==NULL) return;
    	node *tmp;
    	tmp = n->left;
    	if(tmp)
        	while(tmp)
        	{
            	postOrder(tmp);
            	tmp = tmp->right;
        	}
			cout << n->data << ' ';
	}

	void postOrder(){postOrder(root);}

	void levelOrder(node *n)
	{
		queue<node *>que;
		node *tmp;

		que.push(n);
		while(!que.empty())
		{
			tmp = que.front();
			que.pop();
			cout << tmp->data << ' ';
			if(tmp->left)que.push(tmp->left);
			tmp = tmp->right;
			while(tmp)
			{
            	if(tmp->left) que.push(tmp->left);
            	cout << tmp->data << ' ';
        	    tmp = tmp->right;
        	}
		}
	}
	void levelOrder(){levelOrder(root);}
};

int main()
{
	binaryTree a;
	int n;
	cin>>n;
	a.makeTree(n);

	return 0;
}