#include <iostream>
//基于线性表的优先级队列
using namespace std;

template<class T>
class priorityQueue
{
private:
	int currentLength;
	T *array;
	int maxSize;

	void doubleSpace()
	{
		T *tmp = array;

		maxSize*=2;
		array = new T[maxSize];
		for(int i = 1;i<=currentLength;++i)
			array[i] = tmp[i];
		delete []tmp;
	}

	void buildHeap()
	{
		for(int i = currentLength/2;i>0;i--)
			percolateDown(i);
	}

	void percolateDown(int hole)
	{
		int child;
		T tmp = array[hole];
		for(;hole*2 <= currentLength;hole = child)
		{
			child = hole*2;
			if(child!=currentLength&&array[child+1]<array[child])
				child++;
			if(array[child]<tmp)array[hole] = array[child];
			else break;
		}
		array[hole] = tmp;
	}
public:
	priorityQueue(int capacity = 100)
	{
		array = new T[capacity];
		maxSize = capacity;
		currentLength = 0;
	}

	priorityQueue(const T *item,int size):maxSize(size+10),currentLength(size)
	{
		array = new T[maxSize];
		for(int i=0;i<size;i++)
			array[i+1] = item[i];
		buildHeap();
	}

	~priorityQueue(){delete []array;}


	bool isEmpty()const{return currentLength == 0;}

	void enQueue(const T &x)
	{
		if(currentLength == maxSize -1) doubleSpace();

		//向上过滤
		int hole = ++currentLength;
		for(;hole>1&&x<array[hole/2];hole /= 2)
			array[hole] = array[hole/2];
		array[hole] = x;
	}

	T deQueue()
	{
		T minLtem;
		minLtem = array[1];
		array[1] = array[currentLength--];
		percolateDown(1);
		return minLtem;
	}

	T getHeat()const{return array[1];} 
};

int main()
{
	priorityQueue<int> a;
	
	return 0;
}