#include <iostream>
//利用了二叉堆
using namespace std;

class priorityQueue
{
private:
	int *array;
	int currentLength;
	int maxSize;

	void doubleSpace()
	{
		int *tmp = array;

		maxSize*=2;
		array = new int[maxSize];
		for(int i = 1;i<=currentLength;++i)
			array[i] = tmp[i];
		delete []tmp;
	}

	void buildHeap(){}

	void percolateUp(int hole)//向上过滤
	{
		int parent;//该节点的根节点
		int tmp = array[hole];//该节点值

		for(;hole/2>=1;hole = parent)
		{
			parent = hole/2;//指向父母；
			if(array[parent] > tmp)array[hole] = array[parent];
			else break;
		}
		array[hole] = tmp;

	}

	void percolateDown(int hole)//向下过滤
	{
		int child;//儿子指针
		int tmp = array[hole];

		for(;hole*2<=currentLength;hole = child)//判断条件：有左儿子；每步赋值给儿子
		{
			child = hole*2;//儿子指向左儿子
			if(child != currentLength&&array[child+1]<array[child])
				child++;//如果右儿子优先级大于左儿子，儿子指向右儿子
			if(array[child] < tmp)array[hole] = array[child];//如果当前儿子优先级大于当前节点，进行赋值
			else break;		
		}
		array[hole] = tmp;
	}
public:
	priorityQueue(int capacity = 10000)
	{
		maxSize = capacity;
		array = new int[capacity];
		currentLength = 0;
	}//构造函数
	//priorityQueue(int data[],int size){}//本构造函数在此题无用
	~priorityQueue(){delete []array;}//析构函数

	void enQueue(int x)
	{
		if(currentLength + 1 == maxSize)doubleSpace();
		//如果空间满了开空间

		array[currentLength+1] = x;
		++currentLength;//加入一个空结点
		percolateUp(currentLength);//向上过滤
	}

	int deQueue()
	{
		int minItem;
		minItem = array[1];
		array[1] = array[currentLength--];
		percolateDown(1);
		return minItem;
	}

	int getHead()const{return array[1];}

	int isEmpty(){return currentLength == 0;}

	void find(int x)
	{
		int i=1,t,r;
		bool j = 1;
		for(;i<=currentLength;i++)//遍历
			if(array[i]>x)//如果优先级大于x
			{
				if(j){t = array[i];r = i;j = 0;}//如果是第一个直接赋值
				else{//否则
					if(array[i]<t)//如果当前最小值大于此数
					{
						t = array[i];//赋值
						r = i;
					}
				}
			}
		cout<<r<<endl;		
	}

	void insert(int x)
	{
		enQueue(x);
	}

	void decrease(int i,int v)
	{
		array[i]-=v;
		percolateDown(i);
		percolateUp(i);
	}

	void show()
	{
		cout<<"array:";
		for(int i = 1;i<currentLength+1;i++)
			cout<<array[i]<<' ';
	}
	
};


int main()
{
	priorityQueue a;
	int n,x,y;char order[10];
	cin>>n;

	while(n>0)
	{
		--n;
		cin>>order;
		if(order[0]=='i')
		{
			cin>>x;
			a.insert(x);
		}
		else{
			if(order[0]=='f')
			{
				cin>>x;
				a.find(x);
			}
			else{
				if(order[0]=='d')
				{
					cin>>x>>y;
					a.decrease(x,y);
				}
			}
		}
	}


	return 0;
}