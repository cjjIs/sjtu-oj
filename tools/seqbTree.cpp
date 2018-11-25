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

class seqbTree:
{
private:
	int *data;
	int cLength;
	int maxSize;
public:
	seqbTree(int n){maxSize = n+1;data = new int[n+1]};

	void clear(){cLength = 0;}

	bool isEmpty(){return cLength == 0;}

	int root(){return data[0];}

	void creatTree()
	{
		int num,inputnum = 0;
		cin>>num;

		if(num == 0){cout<<'N'<<endl;return;};

		int left,right;
		cin>>left>>right;
		inputnum++;
		while(1)
		{
			data[num+1-inputnum]=inputnum;
			
			if(left != 0)
			{
				realnum++;
				data
			}
			if(realnum == num) return;
			cin>>left>>right;
		}
	}

	~seqbTree(){delete []date;}
	
};

int main()
{
	cout<<"hello world"<<endl;
	return 0;
}