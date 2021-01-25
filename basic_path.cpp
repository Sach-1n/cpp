#include <iostream>
#include <list>
using namespace std;

class GRAPH {
	int Vertex;
	list<int>* adj;


	void print_all_paths_when(int, int, bool[], int[], int&);

public:
	GRAPH(int Vertex);
	void add_edge(int u, int v);
	int print_all_paths(int s, int d);
};

GRAPH::GRAPH(int Vertex)
{
	this->Vertex = Vertex;
	adj = new list<int>[Vertex];
}

void GRAPH::add_edge(int u, int v)
{
	adj[u].push_back(v);
}

int GRAPH::print_all_paths(int s, int d)
{

	bool* visited = new bool[Vertex];

	int* path = new int[Vertex];
	int path_index = 0;
	for (int i = 0; i < Vertex; i++)
		visited[i] = false;
	print_all_paths_when(s, d, visited, path, path_index);
    return path_index;
}

void GRAPH::print_all_paths_when(int u, int d, bool visited[],
							int path[], int& path_index)
{

	visited[u] = true;
	path[path_index] = u;
	path_index++;

	if (u == d) {
		for (int i = 0; i < path_index; i++)
			cout << path[i] << " ";
		cout << endl;
	}
	else
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				print_all_paths_when(*i, d, visited, path, path_index);
	}
	path_index--;
	visited[u] = false;
}

int main()
{

	GRAPH g(11);
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(1,7);
	g.add_edge(2,3);
	g.add_edge(2,4);
	g.add_edge(4,5);
    g.add_edge(4,10);
    g.add_edge(7,8);
    g.add_edge(7,9);
    g.add_edge(0,10);
    g.add_edge(3,10);
    g.add_edge(6,10);
    g.add_edge(7,10);
    g.add_edge(8,10);
	int s = 0, d = 10;
	cout << "ALL the different paths from " << s << " to " << d << " :-\n\n";
	g.print_all_paths(s, d);



	return 0;
}
