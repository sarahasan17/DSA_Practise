#include <iostream>
using namespace std;
#include <queue>
//priority queues for min heap
int main(){
    priority_queue<int,vector<int>,greater<int>> q;
    //greater<int> is used to reverse the elements
    //we use vector<int> as an underlying container to store elements
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
