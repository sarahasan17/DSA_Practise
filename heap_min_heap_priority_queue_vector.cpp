#include <iostream>
using namespace std;
#include <queue>
#include <vector>
//priority queues for min heap(directly from vectors/arrays)
//convert min heap: turn the elements to their negative and then reverse then back to positive which poping out
int main(){
    vector<int> a={1,5,2,3,7,8,4};
    for(int i=0;i<a.size();i++){
        a[i]=-a[i];
    }
    priority_queue<int> q(a.begin(),a.end());
    
    //similary for an array we can say arr,arr+length specify
    while(!q.empty()){
        cout<<(-1)*q.top()<<" ";
        q.pop();
    }
}
