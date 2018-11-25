#include <iostream>
using namespace std;
//直接插入排序,时间复杂度O(n²)
template <class T>
void simpleInertSort(T a[],int size)
{
	int k;T tmp;
	for(int i = 1;i < size; ++i)//对后面每一个数进行判别
	{
		tmp = a[i];//待插入元素
		for(k = i - 1;tmp < a[k]&&k>=0;--k)//如果待插入元素小于当前元素
			a[k+1]=a[k];
		a[k+1]=tmp;
	}
}

//希尔排序，直接插入排序的改进。时间复杂度不稳定，最坏情况O(n²)
template <class T>
void shellSort(T a[],int size)
{
	int step,i,j;
	T tmp;
	for(step = size/2;step > 0;step/=2)//step为希尔增量
	{
		for(i = step;i<size;++i)//对相距step的序列直接插入排序
		{
			tmp = a[i];
			for(j = i-step;j>=0&&a[j]>tmp;j-=step)
				a[j+step]=a[j];
			a[j+step] = tmp;
		}
	}
}
//直接选择排序
void simpleSelectSort(T a[],int size)
{
	int i,j,k;//k记录选择过程中最小的元素
	T tmp;

	for(i = 0;i < size - 1;++i)//执行n-1次选择插入过程
	{
		k = i;
		for(j = i+1;j < size;++j)//找最小元素
		{
			if(a[j] < a[k])k=j;
			tmp = a[i];a[i] = a[k];a[k] = tmp;//将最小元素交换到单元
		}
	}
}
//堆排序