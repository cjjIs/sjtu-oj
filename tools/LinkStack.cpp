#include <iostream>

using namespace std;
template <class elemType>
class stack
{
public:
	virtual bool isEmpty()const = 0;//判断栈空
	virtual void push(const elemType &x)=0;//进栈
	virtual elemType pop()=0;//出栈
	virtual elemType top()const = 0;//取栈顶元素
	virtual ~stack(){}//虚析构函数
};

template <class elemType>
class linkStack:public stack<elemType>
{
private:
	struct node
	{
		elemType data;
		node *next;
		node(const elemType &x,node *N = NULL)
		{data = x; next = N;}
		node():next(NULL){}
		~node(){}
	};

	node *top_p;
public:
	 linkStack();
	~ linkStack();
	bool isEmpty()const;
	void push(const elemType &x);
	elemType pop();
	elemType top() const;

};

template <class elemType>
linkStack<elemType>::linkStack()
{
	top_p = NULL;
}

template <class elemType>
linkStack<elemType>::~linkStack()
{
	node *tmp;
	while(top_p!=NULL){
		tmp = top_p;
		top_p = top_p->next;
		delete tmp;
	}
}


template <class elemType>
bool linkStack<elemType>::isEmpty()const
{
	return top_p == NULL;
}


template <class elemType>
void linkStack<elemType>::push(const elemType &x)
{
	top_p = new node(x,top_p);
}


template <class elemType>
elemType linkStack<elemType>::pop()
{
	node *tmp = top_p;
	elemType x = tmp->data;
	top_p = top_p->next;
	delete tmp;
	return x;
}


template <class elemType>
elemType linkStack<elemType>::top()const
{
	return top_p ->data;
}

int main()
{
      linkStack<int>a;
    cout << "Hello world!" << endl;
    return 0;
}
