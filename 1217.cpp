#include <iostream>

using namespace std;
class Bftree
{
public:
	struct node
	{
		node *left,*right;
		int data;
		node(int d,node *l=NULL,node *r=NULL)
		{data=d;left=l;right=r;}
		~node(){}
		
	};
	node *root;

	Bftree(){root = NULL;}
	~Bftree(){};
	
	bool isEmpty()
	{
		return root == NULL;
		//返回1说明空
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
	bool find(int d)
	{
		return find(root,d);
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
};

int main()
{
	int n,n_input,m,m_input;
	Bftree tree;
	cin>>n;
	while(n > 0)
	{
		n--;
		cin>>n_input;
		tree.insert(n_input);
	}
	cin>>m;
	while(m>0)
	{
		m--;
		cin>>m_input;
		if(tree.find(m_input))
			cout<<'Y'<<endl;
		else
			cout<<'N'<<endl;
	}

	return 0;
}
