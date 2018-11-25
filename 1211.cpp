#include <iostream>

using namespace std;

class bTree
{
private:
	int data[100001];
	int n;
	int rn[100001],ln[100001];

public:
	bTree(int m){n = m;}

	void creatTree()
	{
		//所有数组0位都是初始化的值

		if(n<1){cout<<'N'<<endl;return;}
		if(n==1){cout<<'Y'<<endl;return;}
		//最简单两种情况的判断
		int r,l,i = 1,tmp1 = n;
		rn[0] = 0;ln[0] = 0;

		bool *froot;
		froot = new bool[n+1];
		for(int x=0;x<=n;x++)froot[x] = 0;
		//froot寻找根节点
		//r,l,rn,ln,用于暂时存储每个节点的左右孩子,i用来计数，tmp1同理
		for(int j = 0;j<=100000;j++)data[j] = -1;
		//初始化树都为-1
		cin>>l>>r;

		while(1)
		{
			tmp1--;
			rn[i]=r;ln[i]=l;
			froot[r]=1;froot[l]=1;
			i++;
			if(tmp1 < 1)break;
			cin>>l>>r;
		}

		tmp1 = 1;
		data[0] = 0;
		int root = 0;
		for(int y=1;y<=n;y++)
		{
			if(froot[y]==0){root = y;break;}
		}
		data[1] = root;
		//r = rn[root];l = ln[root];
		//int t = root;

		while(tmp1<=n)//层序遍历
		{
			if(data[tmp1]==-1){cout<<"N"<<endl;return;}//如果未到最后一个节点就有空缺，说明不是完全二叉树
			if(ln[data[tmp1]]==0&&rn[data[tmp1]]==0){tmp1++;continue;}
			//如果此节点为叶节点，跳过
			if(ln[data[tmp1]]==0){cout<<"N"<<endl;return;}
			//如果此节点无左儿子但是有右儿子，绝对不是完全二叉树
			if(rn[data[tmp1]]==0){data[2*tmp1] = ln[data[tmp1]];tmp1++;continue;}
			//如果此节点无右儿子，但是有左儿子，对应位置插入左儿子，继续遍历
			data[2*tmp1] =ln[data[tmp1]];data[2*tmp1+1] = rn[data[tmp1]];
			//如果此节点左右儿子都有，都插入对应位置
			tmp1++;
			//对下一个节点判断
		}

		for(i = 1;i<=n;i++)
		{
			if(data[i]==-1){cout<<"N"<<endl;return;}
			//如果是完全二叉树，则数组是被填满的，没有初始化的-1
		}
		cout<<"Y"<<endl;
	}
};



int main()
{
	int n;
	cin>>n;
	bTree a(n);
	a.creatTree();
	return 0;
}
