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

template <class elemType>
class sLinkList:public list<elemType>
{
private:
	struct node{//链表中的节点类
		elemType data;
		node *next;

		node(const elemType &x, node *n = NULL)
			{data = x;next = n;}
		node():next(NULL){}
		~node(){}

	};
	node *head;
	int currentLength;

	node *move(int i)const{
	node *p = head;
	while(i-->=0)p = p->next;
	return p;
}

public:
	sLinkList();
	~sLinkList(){clear();delete head;}

	void clear();
	int length()const {return currentLength;}
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x)const;
	elemType visit(int i)const;
	void traverse()const;

};


template<class elemType>
sLinkList<elemType>::sLinkList()
{
	head = new node;
	currentLength = 0;
}


template<class elemType>
void sLinkList<elemType>::clear()
{
	node *p = head->next,*q;
	head ->next = NULL;
	while(p!=NULL){
		q = p->next;
		delete p;
		p = q;
	}
	currentLength = 0;
}


template<class elemType>
void sLinkList<elemType>::insert(int i,const elemType &x)
{
	node *pos;

	pos = move(i-1);
	pos->next = new node(x,pos->next);
	++currentLength;
}


template<class elemType>
void sLinkList<elemType>::remove(int i)
{
	node *pos ,*delp;

	pos = move(i-1);
	delp = pos->next;
	pos->next = delp->next;//绕过delp
	delete delp;
	--currentLength;
}


template<class elemType>
int sLinkList<elemType>::search(const elemType &x)const
{
	node *p = head->next;
	int i=0;

	while(p!=NULL&&p->data!=x){p = p->next;++i;}
	if(p == NULL)return -1;else return i;

}


template<class elemType>
elemType sLinkList<elemType>::visit(int i)const
{
	return move(i)->data;
}


template<class elemType>
void sLinkList<elemType>::traverse()const
{
	node *p = head->next;
	cout<<endl;
	while(p!=NULL){cout<<p->data<<" ";p = p->next;}
	cout<<endl;
}

int main()
{
      sLinkList<int> s;
    cout << "Hello world!" << endl;
    return 0;
}


