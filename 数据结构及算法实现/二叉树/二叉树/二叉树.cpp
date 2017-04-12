#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	Node();
	Node(const int& x);
	Node(const int &x, Node *left, Node *right);
//private:
	int key;
	Node *lc, *rc;
};
Node::Node()
{
	key = 0;
	lc = rc = NULL;
}
Node::Node(const int &x)
{
	key = x;
	lc = rc = NULL;
}
Node::Node(const int &x, Node *left, Node *right)
{
	key = x;
	lc = left;
	rc = right;
}

void visit(Node *n)
{
	cout << n->key << endl;
}


class BinaryTree
{
	friend class Node;
public:
	BinaryTree();
	~BinaryTree();
	BinaryTree(const BinaryTree &b);
	bool isEmpty() const;
	int getRoot() const;
	int size() const;
	int leaves() const;
	int height() const;
	void clear();
	void makeTree(const int &x, BinaryTree &left, BinaryTree &right);
	void preOrder(void (*visit)(Node *n)) const;
	void inOrder(void (*visit)(Node *n)) const;
	void postOrder(void (*visit)(Node *n)) const;
	BinaryTree& operator =(const BinaryTree &b);
private:
	Node* recCopy(Node *n);
	void pre(void (*visit)(Node *n), Node *c) const;
	void in(void (*visit)(Node *n), Node *c) const;
	void post(void (*visit)(Node *n), Node *c) const;
	int recSize(Node *n) const;
	int recLeaves(Node *n) const;
	int recHeight(Node *n) const;
	void recClear(Node *n);
	
	Node *root;
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{}

BinaryTree::BinaryTree(const BinaryTree &b)
{
	root = recCopy(b.root);
}

Node* BinaryTree::recCopy(Node *n)
{
	if(n == NULL) return NULL;
	Node *tmp = new Node(n -> key);
	tmp -> lc = recCopy(n -> lc);
	tmp -> rc = recCopy(n -> rc);
	return tmp;
}

bool BinaryTree::isEmpty() const
{
	return root == NULL;
}

int BinaryTree::getRoot() const
{
	return root -> key;
}

int BinaryTree::size() const
{
	return recSize(root);
}

int BinaryTree::recSize(Node *n) const
{
	if(n == NULL) return 0;
	return 1 + recSize(n -> lc) + recSize(n -> rc);
}

int BinaryTree::leaves() const
{
	return recLeaves(root);
}

int BinaryTree::recLeaves(Node *n) const
{
	if(n == NULL) return 0;
	else if(n -> lc == NULL && n -> rc == NULL) return 1;
	else return recLeaves(n -> lc) + recLeaves(n -> rc);
}

int BinaryTree::height() const
{
	return recHeight(root);
}

int BinaryTree::recHeight(Node *n) const
{
	if(n == NULL) return 0;
	int l = recHeight(n -> lc);
	int r = recHeight(n -> rc);
	if(l > r) return 1 + l;
	else return 1 + r;
}

void BinaryTree::clear()
{
	recClear(root);
}

void BinaryTree::recClear(Node *n)
{
	Node *tmp = n;
	if(n == NULL) return ;
	recClear(n -> lc);
	recClear(n -> rc);
	n = NULL;
	delete tmp;
}

void BinaryTree::makeTree(const int &x, BinaryTree &left, BinaryTree &right)
{
	root = new Node(x, left.root, right.root);
	left.root = right.root = NULL;
}

void BinaryTree::preOrder(void (*visit)(Node *n)) const
{
	pre(visit, root);
}

void BinaryTree::pre(void (*visit)(Node *n), Node *c) const
{
	if(c)
	{
		visit(c);
		pre(visit, c -> lc);
		pre(visit, c -> rc);
	}
}

void BinaryTree::inOrder(void (*visit)(Node *n)) const
{
	in(visit, root);
}
void BinaryTree::in(void (*visit)(Node *n), Node *c) const
{
	if(c)
	{
		in(visit, c -> lc);
		visit(c);
		in(visit, c -> rc);
	}
}

void BinaryTree::postOrder(void (*visit)(Node *n)) const
{
	post(visit, root);
}
void BinaryTree::post(void (*visit)(Node *), Node *c) const
{
	if(c)
	{
		post(visit, c -> lc);
		post(visit, c -> rc);
		visit(c);
	}
}

BinaryTree& BinaryTree::operator =(const BinaryTree &b)
{
	clear();
	BinaryTree copy(b);
	root = copy.root;
	copy.root = NULL;
	return *this;
}

int main()
{}