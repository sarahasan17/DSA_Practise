#include <iostream>
#include <map>
#include <list>
#include <stack>
using namespace std;

class Graph{
    public:
    map<int,list<int>> adj;
    map<int,bool> visited;
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void DFS(int i){
        stack <int> s;
        s.push(i);
        while(!s.empty()){
             int t=s.top();
             s.pop();
             if(!visited[t]){
                 cout<<t<<" ";
                 visited[t]=true;
             }
             for(auto l=adj[t].begin();l!=adj[t].end();++l){
                 if(!visited[*l]){
                     s.push(*l);
                 }
             }
        }
    }
};
int main(){
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2):" << endl;
    g.DFS(2);
}
