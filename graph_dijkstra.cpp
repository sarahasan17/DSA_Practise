#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
using namespace std;
typedef pair<int,int> npair;

void dijkstra(vector<list<npair>> &adj,int src){
    int n=adj.size();
    priority_queue<npair,vector<npair>,greater<npair>> q;
    vector<int> dist(n,10000);
    q.push(make_pair(0,src));
    dist[src]=0;
    while(!q.empty()){
        int t=q.top().second;
        q.pop();
        for(auto i=adj[t].begin();i!=adj[t].end();i++){
            int v=(*i).first;
            int w=(*i).second;
            if(dist[v]>w+dist[t]){
                dist[v]=dist[t]+w;
                q.push(make_pair(dist[v], v));
            }
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<i<<"  "<<dist[i]<<endl;
    }
}
int main(){
    int V = 9;

    // Create a graph as an adjacency list
    vector<list<npair>> adj(V);

    // Add edges to the graph
    adj[0].push_back(make_pair(1, 4));
    adj[0].push_back(make_pair(7, 8));
    adj[1].push_back(make_pair(0, 4));
    adj[1].push_back(make_pair(2, 8));
    adj[1].push_back(make_pair(7, 11));
    adj[2].push_back(make_pair(1, 8));
    adj[2].push_back(make_pair(3, 7));
    adj[2].push_back(make_pair(5, 4));
    adj[2].push_back(make_pair(8, 2));
    adj[3].push_back(make_pair(2, 7));
    adj[3].push_back(make_pair(4, 9));
    adj[3].push_back(make_pair(5, 14));
    adj[4].push_back(make_pair(3, 9));
    adj[4].push_back(make_pair(5, 10));
    adj[5].push_back(make_pair(2, 4));
    adj[5].push_back(make_pair(3, 14));
    adj[5].push_back(make_pair(4, 10));
    adj[5].push_back(make_pair(6, 2));
    adj[6].push_back(make_pair(5, 2));
    adj[6].push_back(make_pair(7, 1));
    adj[6].push_back(make_pair(8, 6));
    adj[7].push_back(make_pair(0, 8));
    adj[7].push_back(make_pair(1, 11));
    adj[7].push_back(make_pair(6, 1));
    adj[7].push_back(make_pair(8, 7));
    adj[8].push_back(make_pair(2, 2));
    adj[8].push_back(make_pair(6, 6));
    adj[8].push_back(make_pair(7, 7));

    // Perform Dijkstra's algorithm from vertex 0
    dijkstra(adj, 0);
}
