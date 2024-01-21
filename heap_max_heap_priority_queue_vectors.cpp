#include <iostream>
using namespace std;
#include <queue>
#include <vector>
//priority queues for max heap(directly from vectors/arrays)
int main(){
    vector<int> a={1,5,2,3,7,8,4};
    priority_queue<int> q(a.begin(),a.end());
    //similary for an array we can say arr,arr+length specify
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}
