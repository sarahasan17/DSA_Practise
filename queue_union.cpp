#include <iostream>
using namespace std;
#include <queue>
void uniona(queue <int> q,queue <int> q1){
   queue <int> res;
   queue <int> r=q;
   while(!q.empty()){
       res.push(q.front());
       q.pop();
   }
   
   while(!r.empty()){
       int a=r.front();
       int b=0;
       queue<int> t=q1;
       int m=0;
       while(!t.empty()){
           b=t.front();
           t.pop();
           if(a==b){
               m=1;
               break;
           }
       }
       if(m==0){
           res.push(b);
       }
       r.pop();
   }
   while(!res.empty()){
       cout<<res.front()<<' ';
       res.pop();
   }
}
int main(){
    queue <int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    queue <int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(7);
    uniona(q,q1);
}
