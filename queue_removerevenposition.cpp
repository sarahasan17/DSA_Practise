#include <iostream>
using namespace std;
#include <queue>
void removeeven(queue <int> &q){
    int i=1;
    queue <int> t;
    while(!q.empty()){
       if(i%2==0){
           q.pop();
       }
       else{
           t.push(q.front());
           q.pop();
       }
       i++;
    }
    while(!t.empty()){
        q.push(t.front());
        t.pop();
    }
}
void display(queue <int> q){
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
}
int main(){
    queue <int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    removeeven(q);
    display(q);
}
