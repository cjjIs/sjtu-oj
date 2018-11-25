#include <iostream>

using namespace std;
template <class elemType>
class list
{
public:
      virtual void clear()=0;//清除线性表的所有元素
      virtual int length() const = 0;//求线性表的长度
      virtual void insert(int i,const elemType &x)=0;//在第i个位置插入元素
      virtual void remove(int i)=0;//删除第i个元素
      virtual int search(const elemType &x) const = 0;//搜寻线性表中时候出现了x
      virtual elemType visit(int i) const = 0;//访问第i个位置并返回该位置的元素
      virtual void traverse()const = 0;//按序访问线性表的每一个元素
      virtual ~list(){};

};
//Sequential implementation of linear tables
template <class elemType>
class seqList: public list<elemType>
{
private:
	elemType *data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	 seqList(int initSize = 10);
	 ~seqList();
	 void clear();
	 int length()const;
	 void insert(int i,const elemType &x);
	 void remove(int i);
	 int search(const elemType &x)const;
	 elemType visit(int i)const;
	 void traverse()const;
};
template <class elemType>
seqList<elemType>::seqList(int initSize)
{
	data = new elemType[initSize];
	maxSize = initSize;
	currentLength = 0;
}
template <class elemType>
seqList<elemType>::~seqList()
{
      delete []data;
}

template <class elemType>
void seqList<elemType>::clear()
{
	currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length()const
{
	return currentLength;
}

template <class elemType>
void seqList<elemType>::insert(int i , const elemType &x)
{
	if(currentLength == maxSize)doubleSpace();
	for(int j = currentLength;j>i;j--)
	{
		data[j+1] = data [j];
	}
	data[i] = x;
	++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
	for(int j = i;j<currentLength-1;j++)
	{
		data[j]=data[j+1];
	}
	--currentLength;
}
template <class elemType>
int seqList<elemType>::search(const elemType &x)const
{
	for(int i = 0;i<currentLength;++i)
	{
		if(x == data[i])return i;
	}
	return -1;
}

template <class elemType>
elemType seqList<elemType>::visit(int i)const
{
	return data[i];
}

template <class elemType>
void seqList<elemType>::traverse()const
{
	cout<<endl;
	for(int i = 0; i<currentLength;++i)
		cout<<data[i]<<' ';
}
template <class elemType>
void seqList<elemType>::doubleSpace()
{
      elemType *tmp = data;

      maxSize *=2;
      data = new elemType[maxSize];
      for(int i = 0;i<currentLength;++i)
            data[i]=tmp[i];
      delete []tmp;
}
int main()
{

    seqList<int> var(11);
    cout << "Hello world!" << endl;
    return 0;
}
