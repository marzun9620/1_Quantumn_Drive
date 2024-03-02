#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int v);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int v)
{
    adjLists = new list<int>[v];
    numVertices = v;
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);
    list<int>::iterator i;
    while (!queue.empty())
    {
        int curVertex = queue.front();
        cout << "Visited " << curVertex << " ";
        queue.pop_front();

        for (i = adjLists[curVertex].begin(); i != adjLists[curVertex].end(); ++i)

        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}