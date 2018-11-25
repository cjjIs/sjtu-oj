#include <iostream>

using namespace std;
template <class elemType>
class queue
{
public:
	virtual bool isEmpty() const = 0;
	virtual void enQueue(const elemType &x)=0;
	virtual elemType deQueue()=0;
	virtual elemType getHead() const = 0;
	virtual ~queue(){};

};


template <class elemType>
class linkQueue:public queue<elemType>
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

	node *front,*rear;


public:
	linkQueue();
	~linkQueue();
	bool isEmpty()const;
	void enQueue(const elemType &x);
	elemType deQueue();
	elemType getHead() const {return front->data;}
};
template <class elemType>
linkQueue<elemType>::linkQueue()
{
      front = rear = NULL;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
	node *tmp;
	while(front != NULL){
		tmp = front;
		front = front ->next;
		delete tmp;
	}
}

template <class elemType>
bool linkQueue<elemType>::isEmpty()const
{
	return front == NULL;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
	if(rear = NULL){
		rear = new node(x);
		rear->next = rear;
	}
	else
		rear = rear->next  =new node(x,rear->next);
};

template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
	node *tmp = rear->next;
	elemType value = tmp->data;
	if(rear == tmp)rear = NULL;
	else rear->next = tmp->next;
	delete tmp;
	return value;
}
int main()
{
      linkQueue<int> a;
    cout << "Hello world!" << endl;
    return 0;
}
