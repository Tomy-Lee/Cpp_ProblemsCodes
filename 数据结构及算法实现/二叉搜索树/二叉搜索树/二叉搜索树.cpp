#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
	int key;
	Node *lc, *rc;
	Node();
	Node(const int &x);
	Node& operator =(const Node *n);
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

Node& Node::operator =(const Node *n)
{
	key = n -> key;
	lc = rc = NULL;
	return *this;
}

class BSTree
{
public:
	BSTree();
	BSTree(const BSTree &original);
	~BSTree();
	bool empty() const;
	int size() const;
	int height() const;
	int leaves() const;
	void clear() const;
	void pre(void (*visit)(Node *n));
	void in(void (*visit)(Node *n));
	void post(void (*visit)(Node *n));
	bool search(const Node *n, Node &get) const;           //·Çµİ¹éÊ÷ËÑË÷
	bool tree_search(const int &x, int &get) const;        //µİ¹éÊ÷ËÑË÷
	BSTree& insert(const int &x);                          //·Çµİ¹é²åÈë
	bool tree_insert(const int &x);                        //µİ¹é²åÈë
	BSTree& erase(const int &x, int &get);                 //·Çµİ¹éÉ¾³ı
	BSTree& remove(const int &x);                           //µİ¹éÉ¾³ı
	BSTree& operator =(const BSTree &original);
private:
	Node *root;
private:
	void recClear(Node *n) const;
	Node* recCopy(Node *n);
	int recSize(Node *n) const;
	int recHeight(Node *n) const;
	int recLeaves(Node *n) const;
	void recPre(void (*visit)(Node *n), Node *c);
	void recIn(void (*visit)(Node *n), Node *c);
	void recPost(void (*visit)(Node *n), Node *c);
	Node* recSearch(Node *n, const int &x) const;
	bool recInsert(const int &x, Node *n);
	BSTree& recErase(const int &x, Node *n);
};

BSTree::BSTree()
{
	root = NULL;
}

BSTree::BSTree(const BSTree &original)
{
	root = recCopy(original.root);
}

Node* BSTree::recCopy(Node *n)
{
	if(n == NULL) return NULL;
	Node *tmp = new Node(n -> key);
	tmp -> rc = recCopy(n -> rc);
	tmp -> lc = recCopy( n -> lc);
	return tmp;
}

BSTree::~BSTree()
{
	clear();
}

void BSTree::clear() const
{
	recClear(root);
}

void BSTree::recClear(Node *n) const
{
	Node *tmp = n;
	if(n == NULL) return ;
	recClear(n -> lc);
	recClear(n -> rc);
	n = NULL;
	delete tmp;
	
}

bool BSTree::empty() const
{
	return root == NULL;
}

int BSTree::size() const
{
	return recSize(root);
}

int BSTree::recSize(Node *n) const
{
	if(n == NULL) return 0;
	return 1 + recSize(n -> lc) + recSize(n -> rc);
}

int BSTree::height() const
{
	return recHeight(root);
}

int BSTree::recHeight(Node *n) const
{
	if(n == NULL) return 0;
	int l = recHeight(n -> lc);
	int r = recHeight(n -> rc);
	if(l > r) return 1 + l;
	else return 1 + r;
}

int BSTree::leaves() const
{
	return recLeaves(root);
}

int BSTree::recLeaves(Node *n) const
{
	if(n == NULL) return 0;
							
	if(n -> lc == NULL && n -> rc == NULL) return 1;
	return recLeaves(n -> lc) + recLeaves(n -> rc);
}

void BSTree::pre(void (*visit)(Node *n))
{
	return recPre(visit, root);
}

void BSTree::recPre(void (*visit)(Node *n), Node *c)
{
	if(c == NULL) return ;
	visit(c);
	recPre(visit, c -> lc);
	recPre(visit, c -> rc);
}

void BSTree::in(void (*visit)(Node *n))
{
	return recIn(visit, root);
}

void BSTree::recIn(void (*visit)(Node *n), Node *c)
{
	if(c == NULL) return ;
	recIn(visit, c -> lc);
	visit(c);
	recIn(visit, c -> rc);
}

void BSTree::post(void (*visit)(Node *n))
{
	return recPost(visit, root);
}

void BSTree::recPost(void (*visit)(Node *n), Node *c)
{
	if(c == NULL) return ;
	recPost(visit, c -> lc);
	recPost(visit, c -> rc);
	visit(c);
}

bool BSTree::tree_search(const int &x, int &get) const
{
	Node *tmp = recSearch(root, x);
	if(tmp == NULL)
		return false;
	else
	{
		get = tmp -> key;
		return false;
	}
}

Node* BSTree::recSearch(Node *n, const int &x) const
{
	if( !n ) return NULL;
	if(n -> key == x) return n;
	else if(n -> key < x)
		return recSearch(n -> rc, x);
	else
		return recSearch(n -> lc, x);
}

bool BSTree::search(const Node *n, Node &get) const
{
	Node *tmp = root;
	while(tmp)
	{
		if(n -> key > tmp -> key) tmp = tmp -> rc;
		else if(n -> key < tmp -> key) tmp = tmp -> lc;
		else
		{
			get = tmp;
			return true;
		}
	}
	return false;
}

BSTree& BSTree::insert(const int &x)
{
	if(root == NULL) 
	{
		root = new Node(x);
		return *this;
	}
	Node *tmp = root;
	Node *uptmp;
	while(tmp)
	{
		uptmp = tmp;
		if(x > tmp -> key) tmp = tmp -> rc;
		else if(x < tmp -> key) tmp = tmp -> lc;
		else return *this;
	}
	Node *copy = new Node(x);
	if(x > uptmp -> key) uptmp -> rc = copy;
	else uptmp -> lc = copy;
	return *this;
}

bool BSTree::tree_insert(const int& x)
{
	return recInsert(x, root);
}

bool BSTree::recInsert(const int &x, Node *n)
{
	if(n == NULL)
	{
		n = new Node(x);
		return true;
	}
	else if(n -> key < x)
		return recInsert(x, n -> rc);
	else if(n -> key > x)
		return recInsert(x, n -> lc);
	else
		return false;
}

BSTree& BSTree::erase(const int &x, int &get)
{
	Node *tmp = root, *uptmp = 0;
	while(tmp -> key != x && tmp != NULL)
	{
		uptmp = tmp;
		if(tmp -> key < x)
			tmp = tmp -> rc;
		else if(tmp -> key > x)
			tmp = tmp -> lc;
		else 
			return *this;
	}
	get = tmp -> key;
	if(tmp -> lc != NULL && tmp -> rc != NULL)
	{
		Node *max = tmp -> lc, *upmax = tmp;
		while(max -> rc)
		{
			upmax = max;
			max = max -> rc;
		}
		tmp -> key = max -> key;
		tmp = max;
		uptmp = upmax;
	}
	Node *c;
	if(tmp -> lc) c = tmp -> lc;
	else c = tmp -> rc;
	if(root == tmp) 
		root = c;
	else
	{
		if(tmp == uptmp -> lc)
			uptmp -> lc = c;
		else
			uptmp -> rc = c;
	}
	delete tmp;
	return *this;
}

BSTree& BSTree::operator =(const BSTree &original)
{
	clear();
	root = recCopy(original.root);
	return *this;
}

BSTree& BSTree::remove(const int &x)
{
	recErase(x, root);
	return *this;
}

BSTree& BSTree::recErase(const int &x, Node *n)
{
	if(n == NULL)
		return *this;
	else if(n -> key == x)
	{
		Node *to_delete = n -> lc, *parent = n;
		if(to_delete -> rc != NULL && to_delete -> lc != NULL)
		{
			while(to_delete -> rc)
			{
				parent = to_delete;
				to_delete = to_delete -> rc;
			}
			n -> key = to_delete -> key;
			if(parent == n) n -> lc = to_delete -> lc;
			else parent -> rc = to_delete -> lc;
		}
		else if(n -> rc == NULL) 
			n = n -> lc;
		else if(n -> lc == NULL)
			n = n -> rc;
		delete to_delete;
		return *this;
	}
	else if(n -> key < x)
		return recErase(x, n -> rc);
	else
		return recErase(x, n -> lc);
}

int main()
{
	return 0;
}