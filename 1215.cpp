#include <iostream>

using namespace std;
class BinomialHeap
{
private:
	struct node
	{
		int data;
		int degree;//度数
		node *child;
		node *parent;
		node *next;//左儿子、爹、兄弟

		node(int d)
		{
			data = d;degree = 0;
			child = NULL;
			parent = NULL;
			next = NULL;
		}
	}

	node *heap;
	node *mRoot;
public:
	BinomialHeap();
	~BinomialHeap();
	
};

int main()
{

	return 0;
}