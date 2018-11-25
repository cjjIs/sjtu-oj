#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <map>
#include <queue>
#include <list>
#include <stack>
using namespace std;



//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class seqList
{
private:
	int *data;
	int cLength;
	int maxSize;

	void doubleSpace()
	{
		maxSize*=2;
		int *tmp=data;
		data=new int[maxSize];
		for (int i=0;i<cLength;i++)
			data[i]=tmp[i];
		delete [] tmp;
	}

public:
	seqList(int l=10)
	{
		data=new int[l];
		cLength=0;
		maxSize=l;
	}

	void insert(int d,int p)
	{
		if(cLength+1>maxSize)
			doubleSpace();
		int i;
		for (i=cLength;i>=p;i--)
			data[i]=data[i-1];
		data[i]=d;
		cLength++;
	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class linkList
{
private:
	struct node
	{
		int data;
		node *next;
		node *pre;
		node(int d=0,node *n=NULL,node *p=NULL){data=d;next=n;pre=p;}
		~node(){};
	};

	int length;
	node *head;
	node *rear;

public:
	linkList()
	{
		length=0;
		head=new node;
		rear=new node;
		head->next=rear;
		rear->pre=head;
	}

	void insert(int d,int p)
	{
		node *tmp=head;
		for (int i=0;i<p;i++)
			tmp=tmp->next;
		node *t=new node(d,tmp->next,tmp);
		tmp->next->pre=t;
		tmp->next=t;
		length++;
	}

	void remove(int p)
	{
		node *tmp=head;
		for (int i=0;i<p;i++)
			tmp=tmp->next;
		node *t=tmp->next;
		tmp->next=t->next;
		t->next->pre=tmp;
		delete t;
		length--;
	}

	int search(int d)
	{
		node *tmp=head;
		int i=0;
		while (tmp->next!=rear)
		{
			if (tmp->next->data==d)
				return i;
			else
			{
				i++;
				tmp=tmp->next;
			}
		}
		return -1;
	}

	void clear()
	{
		node *tmp=head->next;
		while (tmp!=rear)
		{
			node *p=tmp;
			tmp=tmp->next;
			delete p;
		}
		head->next=rear;
		rear->pre=head;
		length=0;
	}

	~linkList()
	{
		clear();
		delete head,rear;
	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class seqStack
{
private:
	int *data;
	int pos;
	int maxSize;

	void doubleSpace()
	{
		maxSize*=2;
		int *tmp=data;
		data=new int[maxSize];
		for (int i=0;i<pos;i++)
			data[i]=tmp[i];
		delete [] tmp;
	}

public:
	seqStack(int s=10)
	{
		maxSize=s;
		data=new int[maxSize];
		pos=0;
	}

	void push(int d)
	{
		if (pos==maxSize)
			doubleSpace();
		data[pos]=d;
		pos++;
	}

	int pop()
	{
		if (pos==0)
			return -1;
		pos--;
		return data[pos];
	}

	bool isEmpty(){return pos==0;}

	~seqStack(){delete data;};
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class linkStack
{
private:
	struct node
	{
		int data;
		node *next;
		node *pre;
		node(int d=0,node *n=NULL,node *p=NULL){data=d;next=n;pre=p;}
		~node(){};
	};

	node *head;
	node *pos;
	
public:
	linkStack()
	{
		head=new node();
		pos=head;
	}

	void push(int d)
	{
		pos->next=new node(d,NULL,pos);
		pos=pos->next;
	}

	int pop()
	{
		node *tmp=pos;
		pos=pos->pre;
		int t=tmp->data;
		delete tmp;
		return t;
	}

	bool isEmpty(){return pos==head;}

	~linkStack()
	{
		node *p=head->next;
		while (p!=NULL)
		{
			node *q=p;
			p=p->next;
			delete q;
		}
	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class seqQueue
{
private:
	int *data;
	int maxSize;

	int front;
	int rear;

	void doubleSpace()
	{
		int *tmp=data;
		data=new int[maxSize*2];
		for (int i=1;i<maxSize;i++)
			data[i]=tmp[(front+i)%maxSize];
		front=0;
		rear=maxSize-1;
		maxSize*=2;
		delete [] tmp;
	}

public:
	seqQueue(int s=10)
	{
		maxSize=s;
		data=new int[maxSize];
		front=rear=0;
	}

	void enQueue(int d)
	{
		if ((rear+1)%maxSize==front)
			doubleSpace();
		rear=(rear+1)%maxSize;
		data[rear]=d;
	}

	int deQueue()
	{
		front=(front+1)%maxSize;
		return data[front];
	}

	bool isEmpty(){return front==rear;}

	~seqQueue(){delete [] data;}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class linkQueue
{
private:
	struct node
	{
		int data;
		node *next;
		node(int d=0,node *n=NULL){data=d;next=n;}
		~node(){};
	};

	node *front;
	node *rear;

public:
	linkQueue()
	{
		front=new node();
		rear=front;
	}

	void enQueue(int d)
	{
		if (rear==NULL)
			front=rear=new node(d);
		else
		{
			rear->next=new node(d);
			rear=rear->next;
		}
	}

	int deQueue()
	{
		int t=front->data;
		node *tmp=front;
		front=front->next;
		if (front==NULL)
			rear=front;
		delete tmp;
		return t;
	}

	bool isEmpty(){return front==rear;}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class binaryTree
{
private:
	struct node
	{
		int data;
		node *left;
		node *right;
		node(int d=0,node *l=NULL,node *r=NULL){data=d;left=l;right=r;}
		~node(){};
	};

	node *root;

public:
	binaryTree(int d=0){root=new node(d);}

	node* findRoot(){return root;}

	void clear(node *n)
	{
		if (n->left!=NULL)
			clear(n->left);
		if (n->right!=NULL)
			clear(n->right);
		delete n;
	}

	// use clear(node *n = root) maybe better, this func is of no use... // No, this has its use.
	void clear(){clear(root);root=NULL;}

	bool isEmpty(){return root==NULL;}

	void makeTree(int x,binaryTree *l,binaryTree *r)
	{
		clear();
		root=new node(x,l->findRoot(),r->findRoot());
	}

	void preOrder(node *n)
	{
		cout<<n->data<<' ';
		if (n->left!=NULL)
			preOrder(n->left);
		if (n->right!=NULL)
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
		if (n->left!=NULL)
			midOrder(n->left);
		if (n->right!=NULL)
			midOrder(n->right);
		cout<<n->data<<' ';
	}

	void postOrder(){postOrder(root);}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

//优先级队列（二项堆）
template <class T>
class pQueue
{
	T *data;
	int cLength;
	int maxSize;

	void doubleSpace()
	{
		maxSize*=2;
		T *tmp=data;
		data=new T[maxSize];
		for (int i=0;i<cLength;i++)
			data[i]=tmp[i];
		delete [] tmp;
	}

	void percolateDown(int p)
	{
		int child;
		T tmp=data[p];

		for (;p*2<=cLength;p=child)
		{
			child=2*p;
			if (child!=cLength && data[child+1]<data[child])
				child++;
			if (data[child]<tmp)
				data[p]=data[child];
			else
				break;
		}
		data[p]=tmp;
	}

public:
	pQueue(int s=10)
	{
		maxSize=s;
		cLength=0;
		data=new T[maxSize+1];
	}

	void enqueue(T d)
	{
		if (cLength==maxSize)
			doubleSpace();
		int t=++cLength;
		for (;t>1 && data[t/2]>d;t/=2)
			data[t]=data[t/2];
		data[t]=d;
	}

	T deQueue()
	{
		T t=data[1];
		data[1]=data[cLength--];
		percolateDown(1);
		return t;
	}

	~pQueue()
	{
		delete [] data;
	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class lHeap
{
private:
	struct node
	{
		int data;
		node *left,*right;
		int npl;

		node (int d=0,node *l=NULL,node *r=NULL)
		{
			data=d;
			left=l;
			right=r;
			npl=(l!=NULL && r!=NULL);
		}

		~node(){}

		bool nplRight()
		{
			if (left==NULL && right!=NULL)
				return false;
			if (left==NULL && right==NULL)
				return true;
			if (left!=NULL && right==NULL)
				return true;
			if (left->npl>=right->npl)
				return true;
			else 
				return false;
		}

		int getNpl()
		{
			if (left!=NULL && right!=NULL)
				return 1;
			else 
				return 0;
		}
	};

	node *root;
	void changeLR(node *n)
	{
		node *tmp=n->left;
		n->left=n->right;
		n->right=tmp;
	}
	
public:
	lHeap(int d)
	{
		root=new node(d);
	}

	node * merge(node *a,node *b)
	{
		if (a==NULL)
			return b;
		if (b==NULL)
			return a;
		if (a->data<b->data)
		{
			a->right=merge(a->right,b);
			if (a->left!=NULL)
				a->left->getNpl();
			if (a->right!=NULL)
				a->right->getNpl();
			if (a->nplRight()==false)
				changeLR(a);
			return a;
		}
		else
		{
			b->right=merge(a,b->right);
			b->left->getNpl();
			b->right->getNpl();
			if (b->nplRight()==false)
				changeLR(b);
			return b;
		}
	}

	void merge(lHeap *b)
	{
		root=merge(root,b->root);
	}

	void preOrder(node *n)
	{
		cout<<n->data<<' ';
		if (n->left!=NULL)
			preOrder(n->left);
		if (n->right!=NULL)
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
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class berTree
{
public:
	struct node
	{
		node *son,*rbro;
		int num;

		node(int n=0,node *s=NULL,node *r=NULL){num=n;son=s;rbro=r;}

		
		int getNodeNum() const
		{
			if (num==0)
				return 0;
			if (son==NULL)
				return 1;
			node *pos=son;
			int i=0;
			for (;pos!=NULL;pos=pos->rbro,i++){}
			return pow(2,i);
		}
	};

	node *root;
	int nodeNum;

	berTree(){root=new node;nodeNum=0;}
	berTree(int x){root=new node(x);nodeNum=1;}

	void clear(node *r)
	{
		node *tmp=r;
		if (tmp->son!=NULL)
			clear(tmp->son);
		if (tmp->rbro!=NULL)
			clear(tmp->rbro);
		delete tmp;
	}

	void clear()
	{
		if (root->son!=NULL)
			clear(root->son);
		root->son=NULL;
		root->num=0;
		nodeNum=0;
	}

	bool isEmpty() const{return nodeNum==0;}

	~berTree(){clear();}
	berTree(const berTree &r){root=new node;copy(*root,*r.root);nodeNum=r.nodeNum;}
	berTree(const node &r)
	{
		root=new node(r.num);
		nodeNum=r.getNodeNum();
		if (r.son!=NULL)
		{
			root->son=new node;
			copy(*root->son,*r.son);
		}
	}

	berTree operator+(const berTree &r) const
	{
		if (this->isEmpty())
			return r;
		if (r.isEmpty())
			return *this;
		if (r.nodeNum==1)
		{
			if (this->root->num>r.root->num)
			{
				berTree tmp(r);
				tmp.root->son=new node(this->root->num);
				tmp.nodeNum=2;
				return tmp;
			}
			else
			{
				berTree tmp(*this);
				tmp.root->son=new node(r.root->num);
				tmp.nodeNum=2;
				return tmp;
			}
		}
		else
		{
			if (this->root->num>r.root->num)
			{
				berTree tmp(r);
				berTree temp(*this);
				node *pos=tmp.root->son;
				for (;pos->rbro!=NULL;pos=pos->rbro){}
				pos->rbro=temp.root;
				tmp.nodeNum=nodeNum+r.nodeNum;
				return tmp;
			}
			else
			{
				berTree tmp(*this);
				berTree temp(r);
				node *pos=tmp.root->son;
				for (;pos->rbro!=NULL;pos=pos->rbro){}
				pos->rbro=temp.root;
				tmp.nodeNum=nodeNum+r.nodeNum;
				return tmp;
			}
		}
	}

	berTree & operator=(berTree *r)
	{
		if (this==r)
			return *this;
		clear();
		copy(*root,*r->root);
		nodeNum=r->nodeNum;
		return *this;
	}

	friend void copy(berTree::node &l,berTree::node &r);
	friend class forest;
};

void copy(berTree::node &l,berTree::node &r)
{
	if (r.son!=NULL)
	{
		l.son=new berTree::node;
		copy(*l.son,*r.son);
	}
	if (r.rbro!=NULL)
	{
		l.rbro=new berTree::node;
		copy(*l.rbro,*r.rbro);
	}
	l.num=r.num;
}

//森林
class forest
{
private:
	berTree **trees;
	int treeNum;
	int min;
	bool hasDel;

public:
	forest()
	{
		trees=new berTree *[1];
		trees[0]=new berTree;
		treeNum=0;
		min=pow(2,30);
		hasDel=false;
	}

	forest(int x)
	{
		treeNum=1;
		trees=new berTree*[1];
		trees[0]=new berTree(x);
		min=x;
		hasDel=false;
	}

	forest(const berTree::node &r)
	{
		treeNum=log(r.getNodeNum())/log(2)+1;
		trees=new berTree *[treeNum];
		for (int i=0;i<treeNum-1;i++)
			trees[i]=new berTree;
		trees[treeNum-1]=new berTree(r);
		min=r.num;
		hasDel=false;
	}

	forest(const forest &r)
	{
		treeNum=r.treeNum;
		trees=new berTree*[treeNum];
		for (int i=0;i<treeNum;i++)
		{
			if (!r.trees[i]->isEmpty())
				trees[i]=new berTree(*r.trees[i]);
			else
				trees[i]=new berTree;
		}
		min=r.min;
		hasDel=false;
	}

	~forest()
	{
		for (int i=0;i<treeNum;i++)
			delete trees[i];
		delete [] trees;
	}

	bool isEmpty() const{return treeNum==0;}

	void clear()
	{
		for (int i=1;i<treeNum;i++)
			delete trees[i];
		trees[0]->clear();
		treeNum=0;
	}

	forest & operator=(forest *x)
	{
		if (this==x)
			return *this;
		clear();
		treeNum=x->treeNum;
		trees=new berTree *[treeNum];
		for (int i=0;i<treeNum;i++)
		{
			if (!x->trees[i]->isEmpty())
				trees[i]=new berTree(*x->trees[i]);
			else
				trees[i]=new berTree;
		}
		return *this;
	}

	forest operator+(const forest &r) const
	{
		if (this->isEmpty())
			return r;
		if (r.isEmpty())
			return *this;
		forest tmp;
		tmp.trees=new berTree *[(treeNum>r.treeNum? treeNum:r.treeNum)+1];
		berTree *carry=new berTree,temp;

		for (int i=0;i<(treeNum>r.treeNum? treeNum:r.treeNum)+1;i++)
		{
			if (i>=(treeNum>r.treeNum? r.treeNum:treeNum) && i<(treeNum>r.treeNum? treeNum:r.treeNum))
			{
				tmp.trees[i]=new berTree(*(treeNum>r.treeNum? trees[i]:r.trees[i])+*carry);
				carry->clear();
			}
			else if (i==(treeNum>r.treeNum? treeNum:r.treeNum))
			{
				tmp.trees[i]=new berTree(*carry);
				tmp.treeNum=(treeNum>r.treeNum? treeNum:r.treeNum)+!carry->isEmpty();
				carry->clear();
			}
			else
				tmp.trees[i]=new berTree(*(trees[i])+*(r.trees[i]));

			if (tmp.trees[i]->nodeNum>pow(2,i))
			{
				if (carry->isEmpty())
				{
					carry=new berTree(*tmp.trees[i]);
					tmp.trees[i]->clear();
				}
				else
				{
					temp=carry;
					*carry=tmp.trees[i];
					*tmp.trees[i]=&temp;
				}
			}
			else
			{
				if (carry->isEmpty()){}
				else
				{
					*tmp.trees[i]=&(*tmp.trees[i]+*carry);
					carry->clear();
					if (tmp.trees[i]->nodeNum>pow(2,i))
					{
						carry=new berTree(*tmp.trees[i]);
						tmp.trees[i]->clear();
					}
				}
			}
		}
		berTree a(*tmp.trees[1]);
		return tmp;
	}

	int findMin() const
	{
		int min=0,minAdd=-1,i=0;
		for (;i<treeNum;i++)
		{
			if (trees[i]->root->num>0)
			{
				min=trees[i]->root->num;
				minAdd=i;
				break;
			}
		}
		for (;i<treeNum;i++)
		{
			if (trees[i]->root->num<min && trees[i]->root->num!=0)
			{
				min=trees[i]->root->num;
				minAdd=i;
			}
		}
		return minAdd;
	}

	void insert(int x)
	{
		forest tmp(x);
		*this=&(*this+tmp);
		if (x<min)
			min=x;
	}

	void del()
	{
		int add=findMin();
		if (add==-1)
			return ;
		int childNum=log(trees[add]->nodeNum)/log(2);
		if (childNum==0)
		{
			trees[add]->root->num=0;
			trees[add]->nodeNum=0;
		}
		else
		{
			forest tmp;
			tmp.treeNum=log(trees[add]->nodeNum)/log(2);
			tmp.trees=new berTree *[tmp.treeNum];
			berTree::node *pos=trees[add]->root->son;
			for (int i=0;i<tmp.treeNum;pos=pos->rbro,i++)
				{tmp.trees[i]=new berTree(*pos);
			}
			trees[add]->clear();
			if (findMin()==-1)
				treeNum=0;
			if (add==treeNum-1)
				treeNum--;
			*this=&(*this+tmp);
		}
		hasDel=true;
	}

	int getMin()
	{
		if (min==pow(2,30))
			return 0;
		if (findMin()==-1)
			return 0;
		if (hasDel)
		{
			min=trees[findMin()]->root->num;
			hasDel=false;
			return min;
		}
		return min;
	}
};



//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

//二分搜索
int binarySearch(int *data,int size,int x)
{
	int high=size-1,low=0,mid;
	while (low<=high)
	{
		mid=(high+low)/2;
		if (data[mid]==x)
			return mid;
		else if (data[mid]<x)
			low=mid-1;
		else
			high=mid+1;
	}
	return -1;
}
//二叉查找树
class binarySearchTree
{
private:
	struct node
	{
		int data;
		node *left,*right;
		node(int d,node *l=NULL,node *r=NULL){data=d;left=l;right=r;}
		~node(){}
	};

	node *root;

public:
	binarySearchTree(int d)
	{
		root=new node(d);
	}

	void insert(node *&r,int d)
	{
		if (r->data>=d)
			insert(r->left,d);
		else
			insert(r->right,d);
	}

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

class closeTable
{
private:
	struct node
	{
		int data;
		int state;
		node (){state=0;}
		~node(){}
	};

	node *array;
	int size;
	int key;

public:
	closeTable(int k,int s=10)
	{
		key=k;
		size=s;
		array=new node[size];
	}

	void insert(int d)
	{
		int pos,initPos;
		pos=initPos=d%key;
		do
		{
			if (array[pos].state!=1)
			{
				array[pos].data=d;
				array[pos].state=1;
				return ;
			}
			if (array[pos].data==d)
				return ;
			pos=(pos+1)%size;
		}
		while (pos!=initPos);
		return ;
	}

	void remove(int d)
	{
		int pos,initPos;
		pos=initPos=d%key;
		do
		{
			if (array[pos].state==1 && array[pos].data==d)
			{
				array[pos].state=2;
				return ;
			}
			if (array[pos].state==0)
				return ;
			pos=(pos+1)%size;
		}
		while (pos!=initPos);
		return ;
	}

	int find(int d)
	{
		int pos,initPos;
		pos=initPos=d%key;
		do
		{
			if (array[pos].state==1 && array[pos].data==d)
			{
				return pos;
			}
			if (array[pos].state==0)
				return false;
			pos=(pos+1)%size;
		}
		while (pos!=initPos);
		return -1;
	}

	void rehash()
	{
		node *tmp=array;
		array=new node[size];
		for (int i=0;i<size;i++)
		{
			if (tmp[i].state==1)
				insert(tmp[i].data);
		}
		delete [] tmp;
	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class openTable
{
private:
	struct node
	{
		int data;
		node *next;
		node(int d,node *n=NULL){data=d;next=n;}
		~node(){}
	};

	struct table
	{
		node *first;
		table(node *f=NULL){first=f;}
	};

	table *array;
	int key;

public:
	openTable(int k=10)
	{
		key=k;
		array=new table[key];
	}

	void insert(int d)
	{
		int pos=d%key;
		if (array[pos].first==NULL)
		{
			array[pos].first=new node(d);
			return ;
		}
		node *tmp=array[pos].first;
		if (tmp->data==d)
			return ;
		while (tmp->next!=NULL && tmp->next->data!=d)
			tmp=tmp->next;
		if (tmp->next==NULL)
			tmp->next=new node(d);
	}

	void remove(int d)
	{
		int pos=d%key;
		node *tmp=array[pos].first;
		if (tmp==NULL)
			return ;
		if (tmp->data==d)
		{
			array[pos].first=tmp->next;
			delete tmp;
		}
		while (tmp->next!=NULL && tmp->next->data!=d)
			tmp=tmp->next;
		if (tmp->next==NULL)
			return ;
		node *t=tmp->next;
		tmp->next=t->next;
		delete t;
	}

	bool find(int d)
	{
		int pos=d%key;
		node *tmp=array[pos].first;
		if (tmp==NULL)
			return false;
		if (tmp->data==d)
			return true;
		while (tmp->next!=NULL && tmp->next->data!=d)
			tmp=tmp->next;
		if (tmp->next==NULL)
			return false;
		return true;
	}

	~openTable()
	{
		for (int i=0;i<key;i++)
		{
			if (array[i].first!=NULL)
			{
				node *p=array[i].first;
				while (p!=NULL)
				{
					node *q=p;
					p=p->next;
					delete q;
				}
			}
		}
		delete [] array;
	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

//冒泡排序
void bubbleSort(int data[],int size)
{
	bool flag=true;
	while (flag)
	{
		flag=false;
		for (int i=0;i<size-1;i++)
		{
			if (data[i]>data[i+1])
			{
				int tmp;
				tmp=data[i];
				data[i]=data[i+1];
				data[i+1]=tmp;
				flag=true;
			}
		}
	}
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


int divide(int data[],int low ,int high)
{
	int tmp=data[low];
	while (low!=high)
	{
		while (low<high && data[high]>=tmp)
			high--;
		if (low<high)
		{
			data[low]=data[high];
			low++;
		}
		while (low<high && data[low]<=tmp)
			low++;
		if (low<high)
		{
			data[high]=data[low];
			high--;
		}
	}
	data[low]=tmp;
	return low;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

//快速排序
void quickSort(int data[],int low,int high)
{
	int mid;
	if (low>=high)
		return ;
	mid=divide(data,low,high);
	quickSort(data,low,mid-1);
	quickSort(data,mid+1,high);
}

void quickSort(int data[],int size)
{
	quickSort(data,0,size-1);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class disjointSet				//Â·¾¶Ñ¹Ëõ+°´¹æÄ£²¢
{
private:
	int *parent;
	int size;

public:
	disjointSet(int s=10)
	{
		size=s;
		parent=new int[size];

		for (int i=0;i<size;i++)
			parent[i]=-1;
	}

	int find(int p)
	{
		if (parent[p]<0)
			return parent[p];
		return parent[p]=find(parent[p]);
	}

	void uni(int p1,int p2)
	{
		if (p1==p2)
			return ;
		if (p1<p2)
		{
			parent[p1]=parent[p2]+parent[p1];
			parent[p2]=parent[p1];
		}
		else
		{
			parent[p1]=parent[p2]+parent[p1];
			parent[p2]=parent[p1];
		}
	}

	~disjointSet(){delete [] parent;}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class adjGraph					//ÎÞÏòÍ¼
{
private:
	int *vers;
	int **edges;
	int numOfEdge;
	int nVer;

public:
	adjGraph(int v)
	{
		numOfEdge=0;
		nVer=v;
		vers=new int[v];
		edges=new int*[v];
		for (int i=0;i<v;i++)
			edges[i]=new int[v];
		for (int i=0;i<v;i++)
			for (int j=0;j<v;j++)
				edges[i][j]=-1;
	}

	void insert(int s,int e,int w)
	{
		if (edges[s][e]!=-1)
			return ;
		edges[s][e]=w;
		edges[e][s]=w;
		numOfEdge++;
	}

	void remove(int s,int e)
	{
		if (edges[s][e]==-1)
			return ;
		edges[s][e]=-1;
		edges[e][s]=-1;
		numOfEdge--;
	}

	bool exist(int s,int e)
	{
		return edges[s][e]!=-1;
	}

	~adjGraph()
	{
		for (int i=0;i<nVer;i++)
			delete [] edges[i];
		delete [] edges;
	}

	void floyd(int inf)
	{
		int **distance;
		int **pre;
		distance=new int*[nVer];
		pre=new int*[nVer];
		for (int i=0;i<nVer;i++)
		{
			distance[i]=new int[nVer];
			pre[i]=new int[nVer];
		}

		for (int i=0;i<nVer;i++)
			for (int j=0;j<nVer;j++)
			{
				distance[i][j]=edges[i][j];
				if (edges[i][j]==-1)
					pre[i][j]=-1;
				else
					pre[i][j]=i;
			}

		for (int k=0;k<nVer;k++)
			for (int i=0;i<nVer;i++)
				for (int j=0;j<nVer;j++)
					if (distance[i][k]+distance[k][j]<distance[i][j])
					{
						distance[i][j]=distance[i][k]+distance[k][j];
						pre[i][j]=pre[k][j];
					}

		for (int i=0;i<nVer;i++)
			for (int j=0;j<nVer;j++)
				cout<<i<<'-'<<j<<'='<<distance[i][j]<<endl;

	}
};

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


class listGraph				//ÓÐÏòÍ¼£¬´øÓÐÍêÕûµÄÍ¼Ààº¯Êý£¨³ýfloydº¯Êý£©
{
private:
	struct edge
	{
		int start;
		int end;
		int weight;
		edge *next;

		edge(int s=0,int e=0,int w=0,edge *n=NULL)
		{
			start=s;
			end=e;
			weight=w;
			next=n;
		}

		bool operator<(const edge &r){return weight<r.weight;}
		bool operator>(const edge &r){return weight>r.weight;}
	};

	struct ver
	{
		int num;
		edge *first;

		ver(int n=0,edge *f=NULL)
		{
			num=n;
			first=f;
		}
	};

	ver *vers;
	int nVer;
	int nEdge;

public:
	listGraph(int v)
	{
		nVer=v;
		nEdge=0;
		vers=new ver[v];
		for (int i=0;i<v;i++)
			vers[i].num=i;
	}

	void insert(int s,int e,int w)
	{
		edge *tmp=vers[s].first;
		if (tmp==NULL)
		{
			tmp=new edge(s,e,w);
			return ;
		}
		if (tmp->start==s && tmp->end==e && tmp->weight==w)
				return ;
		while (tmp->next!=NULL)
		{
			if (tmp->next->start==s && tmp->next->end==e && tmp->next->weight==w)
				return ;
			else
				tmp=tmp->next;
		}
		tmp->next=new edge(s,e,w);
		nEdge++;
	}

	void remove(int s,int e,int w)
	{
		edge *tmp=vers[s].first;
		if (tmp->start==s && tmp->end==e && tmp->weight==w)
		{
			vers[s].first=tmp->next;
			delete tmp;
			return ;
		}
		while (tmp->next!=NULL)
		{
			if (tmp->next->start==s && tmp->next->end==e && tmp->next->weight==w)
			{
				edge *t=tmp->next;
				tmp->next=t->next;
				delete t;
				return ;
			}
			else
				tmp=tmp->next;
		}
		nEdge--;
	}

	bool exist(int s,int e,int w)
	{
		edge *tmp=vers[s].first;
		if (tmp->start==s && tmp->end==e && tmp->weight==w)
			return true;
		while (tmp->next!=NULL)
		{
			if (tmp->next->start==s && tmp->next->end==e && tmp->next->weight==w)
				return true;
			else
				tmp=tmp->next;
		}
		return false;
	}

	~listGraph()
	{
		for (int i=0;i<nVer;i++)
		{
			edge *t=vers[i].first;
			while (t!=NULL)
			{
				edge *p=t;
				t=t->next;
				delete p;
			}
		}
		delete [] vers;
	}

	void dfs(int s,bool *visited)
	{
		edge *t=vers[s].first;
		cout<<vers[s].first<<' ';
		visited[s]=true;

		while (t!=NULL)
		{
			if (visited[t->end]==false)
				dfs(t->end,visited);
			t=t->next;
		}
	}

	void dfs()
	{
		bool *visited;
		visited=new bool[nVer];
		for (int i=0;i<nVer;i++)
			visited[i]=false;

		for (int i=0;i<nVer;i++)
		{
			if (visited[i]==false)
			{
				dfs(i,visited);
				cout<<endl;
			}
		}

		delete [] visited;
	}

	void bfs()
	{
		linkQueue q;
		bool *visited;
		visited=new bool[nVer];

		for (int i=0;i<nVer;i++)
			visited[i]=false;

		for (int i=0;i<nVer;i++)
		{
			if (visited[i]==true)
				continue;
			q.enQueue(i);
			while (!q.isEmpty())
			{
				int tmp=q.deQueue();
				if (visited[tmp])
					continue;
				cout<<tmp<<' ';
				visited[tmp]=true;
				edge *t=vers[tmp].first;
				while (t!=NULL)
				{
					if (!visited[t->end])
						q.enQueue(t->end);
					t=t->next;
				}
			}
			cout<<endl;
		}

		delete [] visited;
	}

	
	void topSort()
	{
		int *inDegree;
		linkQueue q;
		inDegree=new int[nVer];
		for (int i=0;i<nVer;i++)
		{
			edge *tmp=vers[i].first;
			while (tmp!=NULL)
			{
				inDegree[tmp->end]++;
				tmp=tmp->next;
			}
		}

		for (int i=0;i<nVer;i++)
			if (inDegree[i]==0)
				q.enQueue(i);

		while (!q.isEmpty())
		{
			int t=q.deQueue();
			cout<<vers[t].num;
			edge *p=vers[t].first;
			while (p!=NULL)
			{
				inDegree[p->end]--;
				if (inDegree[p->end]==0)
					q.enQueue(p->end);
				p=p->next;
			}
		}
		cout<<endl;
	}

	void kruskal()
	{
		int edgeAccepted=0;
		edge e;
		disjointSet dj;
		pQueue<edge> pq;
		edge *t;

		for (int i=0;i<nVer;i++)
		{
			t=vers[i].first;
			while (t!=NULL)
			{
				e.start=t->start;
				e.end=t->end;
				e.weight=t->weight;
				pq.enqueue(e);
				t=t->next;
			}
		}

		while (edgeAccepted<nVer-1)
		{
			e=pq.deQueue();
			if (dj.find(e.start)!=dj.find(e.end))
			{
				edgeAccepted++;
				dj.uni(e.start,e.end);
				cout<<e.start<<'-'<<e.end<<endl;
			}
		}
	}

	void prim(int noEdge)
	{
		bool *inU;
		int *startNode;
		int *lowCost;
		int start;
		int min;

		inU=new bool[nVer];
		startNode=new int[nVer];
		lowCost=new int[nVer];
		for (int i=0;i<nVer;i++)
		{
			inU[i]=false;
			lowCost[i]=noEdge;
		}

		start=0;
		for (int i=0;i<nVer;i++)
		{
			min=noEdge;
			edge *t;
			t=vers[start].first;
			while (t!=NULL)
			{
				if (lowCost[t->end]>t->weight)
				{
					lowCost[t->end]=t->weight;
					startNode[t->end]=t->start;
				}
				t=t->next;
			}

			inU[start]=true;
			for (int i=0;i<nVer;i++)
			{
				if (inU[i])
					continue;
				if (lowCost[i]<min)
				{
					min=lowCost[i];
					start=i;
				}
			}
			cout<<startNode[start]<<'-'<<start<<endl;
		}

		delete [] inU;
		delete [] startNode;
		delete [] lowCost;
	}

	void printpath(int s,int e,int *pre)
	{
		if (s==e)
		{
			cout<<s;
			return ;
		}

		printpath(s,pre[e],pre);
		cout<<'-'<<e;
	}

	void dijkstra(int s,int noEdge)
	{
		int start;
		int min;
		int u;

		bool *known=new bool[nVer];
		int *pre=new int[nVer];
		int *distance=new int[nVer];
		for (int i=0;i<nVer;i++)
		{
			known[i]=false;
			distance[i]=noEdge;
		}

		start=s;
		known[start]=true;
		pre[start]=start;
		distance[start]=0;

		for (int i=0;i<nVer;i++)
		{
			min=noEdge;
			for (int i=0;i<nVer;i++)
			{
				if (!known[i] && distance[i]<min)
				{
					min=distance[i];
					u=i;
				}
			}

			known[u]=true;
			edge *t=vers[u].first;
			while (t!=NULL)
			{
				if (!known[t->end] && distance[t->start]+t->weight<distance[t->end])
				{
					distance[t->end]=distance[t->start]+t->weight;
					pre[t->end]=u;
				}
			}
		}
	}

	void weightedNegative(int start,int inf)
	{
		linkQueue q;
		int u;
		edge *t;
		int *prev=new int[nVer];
		int *distance=new int[nVer];
		for (int i=0;i<nVer;i++)
			distance[i]=inf;

		distance[start]=0;
		q.enQueue(start);
		while (!q.isEmpty())
		{
			u=q.deQueue();
			t=vers[u].first;
			while (t!=NULL)
			{
				if (!distance[t->start]+t->weight<distance[t->end])
				{
					distance[t->end]=distance[t->end]+t->weight;
					prev[t->end]=t->start;
					q.enQueue(t->end);
				}
				t=t->next;
			}
		}
	}
};

int main()
{
	// system("pause");
	
	return 0;
}