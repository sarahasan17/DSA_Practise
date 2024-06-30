#include <iostream>
using namespace std;
#include <vector>
#include <queue>
//smallest sum of ropes
//min heap using priority queue
int main(){
    vector<int> a={4,3,2,6};
    for(int i=0;i<a.size();i++){
        a[i]=-a[i];
    }
    vector<int> l;
    priority_queue <int> q(a.begin(),a.end());
    int sum;
    int val=0;
    while(!q.empty()){
        int n1=(-1)*q.top();
        q.pop();
        int n2=(-1)*q.top();
        q.pop();
        sum=n1+n2;
        val+=sum;
        if(q.size()>=1){
            q.push(-sum);
        }
    }
    cout<<val<<endl;
}
// METHOD 2
// #include <iostream>
// #include <queue>
// using namespace std;

// int main(){
//     vector<int> a={4,3,2,6};
//     priority_queue<int,vector<int>,greater<int>> q(a.begin(),a.end());
//     int val=0;
//     while(!q.empty()){
//         int n1=q.top();
//         q.pop();
//         int n2=q.top();
//         q.pop();
//         int sum=n1+n2;
//         val+=sum;
//         if(q.size()>=1){
//             q.push(sum);
//         }
//     }
//     cout<<val;
// }

