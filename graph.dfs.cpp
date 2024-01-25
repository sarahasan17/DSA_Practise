#include <iostream>
using namespace std;
#include<map>
#include <list>
#include<queue>
template<typename T>
//dfs:stack bfs:queue
//dfs recursive
class graph{
   public:
   map<T,list<T>> l;
   void addedge(int x,int y){
       l[x].push_back(y);
       l[y].push_back(x);
   }
   void dfs_helper(T src,map<T,bool> &visited){
       cout<<src<<' ';
       visited[src]=true;
       for(T nbr:l[src]){
          if(!visited[nbr]){
              dfs_helper(nbr,visited);
          }
       }
   }
   void dfs(T src){
       map <T,bool> visited;
       for(auto nbr:l){
           T node=nbr.first;
           visited[node]=false;
       }
       dfs_helper(src,visited);
       
   }
    
};
int main(){
    graph<int> g;
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.addedge(4,1);
    g.addedge(3,5);
    g.dfs(1);
}
