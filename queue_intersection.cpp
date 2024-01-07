#include <iostream>
using namespace std;
#include <queue>
void intersection(queue <int> q,queue <int> q1){
   queue <int> q2;
   while(!q.empty()){
       queue <int> t=q1;
       int x=q.front();
       while(!t.empty()){
           int g=t.front();
           t.pop();
           if(x==g){
               q2.push(x);
               break;
           }
       }
       q.pop();
   }
   while(!q2.empty()){
       cout<<q2.front()<<' ';
       q2.pop();
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
    intersection(q,q1);
}
