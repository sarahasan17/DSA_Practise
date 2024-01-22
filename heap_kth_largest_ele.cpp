#include <iostream>
using namespace std;
#include <vector>
#include <queue>
//find kth largest element
//hear we implement max heap(easy way using priority queue) and dequeue it the number of times
//time complexity is O(n) as we use the concept of max heap
int main(){
    vector<int> a={9,7,0,5,8,6,3};
    priority_queue <int> q(a.begin(),a.end());
    int k;
    cout<<"Which largest element do you want to find?"<<endl;
    cin>>k;
    int i=0;
    int top=0;
    while(i<k){
        top=q.top();
        q.pop();
        i++;
    }
    cout<<top<<endl;
}
