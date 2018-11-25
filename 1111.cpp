#include <iostream>

using namespace std;

class bTree
{
private:
	char data[3000];//顺序存储数组
	int n;//非空节点个数
public:
	bTree(int m){n = m;for(int i=0;i<3000;i++)data[i]='@';}//初始化顺序存储的数组
	~bTree(){}
	//i 为存储二叉树的节点的位置；ps是先序遍历所得字符串处理时开始的位置；pe为结束位置；
	//ms为中序遍历所得字符串处理时开始位置；me为结束位置；
	//以下为递归实现函数
	void func(const int i,const int ps,const int ms,const int pe,const int me,char pre[],char mid[])
	{
		 cout<<"chuan ru:"<<endl;
		 cout<<"i,ps,ms,pe,me:"<<i<<' '<<ps<<' '<<ms<<' '<<pe<<' '<<me<<endl;

		if(ms>me)return;//空节点直接返回

		//非空
		char root = pre[ps-1];int r,j;//r用来记录当前节点在mid中的位置

		data[i] = root;//当前节点插入data

		 cout<<root<<' '<<i<<endl;

		for(j = 0;j<n;j++)if(mid[j]==root){r = j+1;cout<<r<<endl;break;}//记录mid中当前节点的位置r

		 cout<<"i,ps,ms,pe,me:"<<i<<' '<<ps<<' '<<ms<<' '<<pe<<' '<<me<<endl;
		 cout<<endl;

		if(ms==me)return;//如果只有一个节点记录后就返回。

		 cout<<"chuanchu"<<endl;
		 cout<<endl;

		func(i*2,ps+1,ms,r+ps-1,r-1,pre,mid);//左子树遍历
		func(i*2+1,r+ps-ms+1,r+1,pe,me,pre,mid);//右子树遍历

		return;

	}
	void show()//输出函数
		{
			int j,i;
			for(j = 1000;j>=0;j--)
			{
				if(data[j]!='@')break;
			}
			for(i =1;i<j+1;i++)
			{
				if(data[i]=='@')cout<<"NULL ";
				else cout<<data[i]<<' ';
			}
		}

	
}; 

int main()
{
	char pre[30],mid[30];
	int n;
	for(int i = 0;i<30;i++)
	{
		pre[i] = '@';mid[i] = '@';
	}

	cin.getline(pre,30,'\n');
	cin.getline(mid,30,'\n');//获得两个遍历的字符串

	for(int j = 1;j<28;j++){if(pre[j]=='@'){n = j-1;break;}}
	//得到节点个数
	// cout<<n<<endl;
	bTree text(n);
	text.func(1,1,1,n,n,pre,mid);
	text.show();


	return 0;
}