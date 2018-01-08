//Justin Seda
#include <iostream>
#include <cstdlib>
using namespace std;
struct Edge
{
	int vertex1;
	int vertex2;
};

void insertEdge(Edge e, int adjMat[5][5]);
void printGraph(int adjMat[5][5]);

int main()
{
	Edge a, b, c, d, e, f, g;
	a.vertex1 = 0;
	a.vertex2 = 1;
	b.vertex1 = 1;
	b.vertex2 = 2;
	c.vertex1 = 2;
	c.vertex2 = 3;
	d.vertex1 = 1;
	d.vertex2 = 3;
	e.vertex1 = 3;
	e.vertex2 = 4;
	f.vertex1 = 4;
	f.vertex2 = 1;
	g.vertex1 = 4;
	g.vertex2 = 0;


	int mat[5][5];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			mat[i][j] = 0;
		}
	}
	cout << "Before inserting edges into the adjacency matrix: " << endl;
	printGraph(mat);

	insertEdge(a, mat);
	insertEdge(b, mat);
	insertEdge(c, mat);
	insertEdge(d, mat);
	insertEdge(e, mat);
	insertEdge(f, mat);
	insertEdge(g, mat);
	cout << "After inserting edges into the adjacency matrix: " << endl;
	printGraph(mat);

	system("pause");
	return 0;
}


void insertEdge(Edge e, int adjMat[5][5]) 
{
	adjMat[e.vertex1][e.vertex2] = 1;
	adjMat[e.vertex2][e.vertex1] = 1;
}


void printGraph(int adjMat[5][5]) 
{
	cout << "   ";
	for (int h = 0; h < 5; h++)
	{
		cout << h << "   ";
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << i << " ";
		for (int j = 0; j < 5; j++)
		{
			cout << "[" << adjMat[i][j] << "] ";
		}
		cout << endl;
	}
}
