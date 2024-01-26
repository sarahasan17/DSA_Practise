#include <iostream>
using namespace std;
#include<map>
#include <list>
#include<queue>
template<typename T>
//Template acts as a blueprint for creating generic functions or classes
class graph{
   public:
   map<T,list<T>> l;
   void addedge(int x,int y){
       l[x].push_back(y);
       l[y].push_back(x);
   }
   void bfs(T src){
       map<T,int> visited;
       queue<T> q;
       q.push(src);
       visited[src]=true;
       cout<<src<<' ';
       while(!q.empty()){
           T node=q.front();
           q.pop();
           for(int d:l[node]){
               if(!visited[d]){
                   cout<<d<<' ';
                   q.push(d);
                   visited[d]=true;
               }
           }
       }
   }
    
};
int main(){
    graph<int> g;
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.addedge(4,1);
    g.bfs(1);
}
