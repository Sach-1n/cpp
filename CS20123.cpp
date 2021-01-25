
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

	GRAPH g(19);
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(1,18);
	g.add_edge(2,3);
	g.add_edge(3,4);
	g.add_edge(3,5);
	g.add_edge(5,6);
	g.add_edge(5,7);
	g.add_edge(7,8);
	g.add_edge(7,9);
	g.add_edge(9,10);
	g.add_edge(9,11);
	g.add_edge(11,12);
	g.add_edge(11,13);
	g.add_edge(13,14);
	g.add_edge(13,15);
	g.add_edge(15,16);
	g.add_edge(15,17);

	cout<<"\nAll Def-Coverage :-\t\t\n\n";
	g.print_all_paths(0,1);
	g.print_all_paths(2,14);


	cout<<"\n\n\nAll C-uses / Some p-uses coverage :-\t\t";
	cout<<"\nFor Variable a,b,c :-\t\t";
	cout<<"\nALL c-uses:-\t\t\n\n";
	g.print_all_paths(0,10);
	g.print_all_paths(0,12);
	g.print_all_paths(0,14);
	g.print_all_paths(0,16);
	cout<<"\nALL c-uses:-\t\t\n";
	g.print_all_paths(0,1);

	cout<<"\n\n\nFor Variable match :-\t\t";
	cout<<"\nALL c-uses:-\t\t\n\n";
	g.print_all_paths(2,4);
	g.print_all_paths(2,6);
	g.print_all_paths(2,8);
	g.print_all_paths(4,6);
	g.print_all_paths(4,8);
	g.print_all_paths(6,8);
	cout<<"\nALL c-uses:-\t\t\n";
	g.print_all_paths(2,9);
	g.print_all_paths(4,9);
	g.print_all_paths(6,9);



	return 0;
}
