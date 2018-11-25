#include <iostream>

using namespace std;

template <class T>
class binaryTree
{
public:
	virtual void clear() = 0;//清除所有树变为空树
	virtual bool isEmpty()const = 0;//判断是否为空树
	virtual T root()const = 0;//返回根节点
	virtual T parent(T x,T flag)const = 0;//返回x节点的父节点
	virtual T leftChild(T x,T falg)const = 0;//返回x节点的左孩子
	virtual T rightChild(T x,T flag)const = 0;//返回x节点的右孩子
	virtual void delLeft(T x) = 0;//删除x节点的左子树
	virtual void delRight(T x) = 0;//删除x节点的右子树
	virtual void preOrder()const = 0;//前序遍历
	virtual void midOrder()const = 0;//中序遍历
	virtual void postOrder()const = 0;//后序遍历
	virtual void levelOrder()const = 0;//层次遍历
	
};

template <class T>
class bTree:public binaryTree<T>
{
	friend void printTree(const bTree &t,T flag);
private:
	struct node
	{
		node *left,*right;
		T data;
		node():left(NULL),right(NULL){}
		node(T item,node *L = NULL,node *R = NULL):data(item),left(L),right(R){}
	};
	node *root;
public:
	bTree()root(NULL){}
	bTree(T x){root = new node(x);}
	~bTree();
	void clear();
	bool isEmpty();
	T root(T flag)const;
	T leftChild(T x,T flag)const;
	T rightChild(T x,T flag)const;
	void delLeft(T x);
	void delRight(T x);
	void preOrder()const;
	void midOrder()const;
	void postOrder()const;
	void levelOrder()const;
	void createTree(T flag);
	T parent(T x,T falg)const{return flag;}
private:
	node *find(T x,node *t)const;
	void clear(node *&t);
	void preOrder(node *t)const;
	void midOrder(node *t)const;
	void postOrder(node *t)const;

	
};

template <class T>
bool bTree<T>::isEmpty()const
{
	return root = NULL;
}

template <class T>
T bTree<T>::root(T flag)const
{
	if(root != NULL)return root->data;
	return flag;
}

template <class T>
T bTree<T>::clear(bTree<T>::node *&t)
{

	if(t == NULL)return;
	clear(t->left);
	clear(t->right);
	delte t;
	t = NULL;
}

template <class T>
void bTree<T>::clear()
{
	clear(root);
}

template <class T>
bTree<T>::~bTree()
{
	clear(root);
}

template <class T>
bTree<T>::node *bTree<T>::find(T x,bTree<T>::node *t)const
{
	node *tmp;
	if(t == NULL)return NULL;
	if(t->data == x) return t;
	if(tmp = find(x,t->left))return tmp;
	else return find(x,t->right);
}

template <class T>
void bTree<T>::delLeft(T x)
{
	node *tmp = find(x,root);
	if(tmp == NULL)return;
	clear(tmp->left);
}
zd
template <class T>
void bTree<T>::delRight(T x)
{
	node *tmp = find(x);
	if(tmp == NULL)return;
	clear(tmp -> right);
}

template <class T>
void bTree<T>::leftChild(T x,T flag)const
{
	node *tmp = find(x);
	if(tmp == NULL||tmp -> left == NULL) return flag;
	return tmp -> left ->data;
}

template <class T>
void bTree<T>::rightChild(T x,T flag)const
{
	node *tmp = find(x);
	if(tmp == NULL||tmp -> right = NULL) return flag;
	return tmp -> right -> data;
}

template <class T>
void bTree<T>::createTree(T flag)
{
	
}
int main()
{
	cout<<"hello world"<<endl;
	return 0;
}