#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph{
    public:
    map <int,list<int>> adj;
    map<int,bool> visited;
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void BFS(int i){
        queue <int>q;
        q.push(i);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(!visited[t]){
                cout<<t<<" ";
                visited[t]=true;
            }
            for(auto i=adj[t].begin();i!=adj[t].end();i++){
                if(!visited[*i]){
                    q.push(*i);
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
    g.BFS(2);
}
