#include <iostream>
using namespace std;

#define INF 99999
class WGraph
{
public:
	WGraph( int s );
	~WGraph();

	bool empty() const;
	int getEdge() const;
	int getVertex() const;

	bool add( int i, int j, int weight );
	bool erase( int i, int j, int &get );

	void prim( WGraph &tree, int s );
	void print() const;
private:
	int edge;
	int vertex;
	int size;
	int m[30][30];
	
protected:
	bool check( int i ) const;
};

WGraph::WGraph( int s )
{
	size = s;
	edge = 0;
	vertex = 0;

	for( int i = 0; i < size; i++ )
		for( int j = 0; j < size; j++ )
			m[i][j] = INF;
}

WGraph::~WGraph()
{}

bool WGraph::empty() const
{
	return edge == 0;
}

int WGraph::getEdge() const
{
	return edge;
}

int WGraph::getVertex() const
{
	return vertex;
}

bool WGraph::add( int i, int j, int weight )
{
	if( check( i ) && check( j ) )
	{
		m[i][j] = m[j][i] = weight;
		return true;
	}
	else 
		return false;
}

bool WGraph::erase( int i, int j, int &get )
{
	if( check( i ) && check( j ) )
	{
		get = m[i][j];
		m[i][j] = m[j][i] = INF;
		return true;
	}
	else 
		return false;
}

bool WGraph::check( int i ) const
{
	bool flag = ( i < size ) && ( i >= 0 );
	return flag;
}

void WGraph::print() const
{
	for( int i = 0; i < size; i++ )
	{
		for( int j = 0; j < size; j++ )
		{
			if( m[i][j] == INF )
				cout << "¡Þ" << "  ";
			else
				cout << " " << m[i][j] << "  ";
		}
		cout << endl;
	}
}

void WGraph::prim( WGraph &tree, int s )
{
	bool visited[30];
	int dis[30];
	int adj[30];
	int vtex;

	for( vtex = 0; vtex < size; vtex++ )
	{
		visited[vtex] = false;
		dis[vtex] = m[s][vtex];
		adj[vtex] = s;
	}
	
	visited[s] = true;
	for( int i = 1; i < size; i++ )
	{
		int to_insert;
		int min = INF;
		for( vtex = 0; vtex < size; vtex++ )
			if( !visited[vtex] )
				if( dis[vtex] < min )
				{
					to_insert = vtex;
					min = dis[vtex];
				}

		if( min < INF )
		{
			visited[to_insert] = true;
			tree.add( to_insert, adj[to_insert], dis[to_insert] );
			for( vtex = 0; vtex < size; vtex++ )
				if( !visited[vtex] )
					if( m[to_insert][vtex] < dis[vtex] )
					{
						dis[vtex] = m[to_insert][vtex];
						adj[vtex] = to_insert;
					}
		}
		else break;
	}
}

int main()
{
	WGraph graph( 6 );
	WGraph tree( 6 );
	
	graph.add( 0, 1, 6 );
	graph.add( 0, 2, 1 );
	graph.add( 0, 3, 5 );
	graph.add( 1, 2, 5 );
	graph.add( 1, 4, 3 );
	graph.add( 2, 3, 5 );
	graph.add( 2, 4, 6 );
	graph.add( 2, 5, 4 );
	graph.add( 3, 5, 2 );
	graph.add( 4, 5, 6 );
	graph.print();
	cout << endl << endl;
	graph.prim( tree, 0 );
	tree.print();
	system("pause");
	return 0;
}