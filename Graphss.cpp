#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:

	map<int, list<int>> adj;
	
void BFS(int v)
{
	map<int, bool> visit;
	queue<int> q;
	
	q.push(v);
	visit[v] = true;
	
	list<int>::iterator i;
	
    while(!q.empty())
    {
        v = q.front();
        cout << v << endl;
        q.pop();
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visit[*i])
            {
                visit[*i] = true;
                q.push(*i);
            }
        }
        
    }
}


void DFS(int v)
{
	map<int, bool> visited;
	stack<int> s;
	
	s.push(v);
	
	list<int>::iterator i;
    while(!s.empty())
    {
        v = s.top();
        s.pop();
        if (!visited[v])
        {
        	cout << v << endl;
        	visited[v] = true;
        }
        	
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i])
            {
                s.push(*i);
            }
        }
        
    }
}

void addEdge(int v, int w)
{
	adj[v].push_back(w); 
}


};






int main()
{
	Graph g;
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 6);
	g.addEdge(3, 5);
	g.addEdge(3, 7);
	g.addEdge(7, 5);
	g.addEdge(5, 2);
	g.addEdge(5, 6);
	g.addEdge(6, 1);
	g.addEdge(4, 6);
	
	
	cout << "Following is Depth First Traversal"
			" (starting from vertex 1) \n";
	g.DFS(1);
	cout << "Following is Breadth First Traversal"
			" (starting from vertex 1) \n";
	g.BFS(1);
	return 0;
}