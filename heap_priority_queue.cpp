#include <iostream>
using namespace std;
#include <queue>
//priority queues are easy and direct implementation of max heap with much algo
int main(){
    priority_queue<int> q;
    q.push(10);
    q.push(15);
    q.push(5);
    q.push(26);
    q.push(18);
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}
