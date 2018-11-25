#include <iostream>

using namespace std;
template <class T>
class tree
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual T root() const = 0;
	virtual T parent(T x,T flag)const = 0;
	virtual T child(T x,int i, T flag)const = 0;
	virtual void remove(T x,int i) = 0;
	virtual void traverse() const = 0;
	
};
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
