#include <iostream>
using namespace std;
#include <queue>
double average(queue<int>& q){
    int sum=0;
    int n=q.size();
    while(!q.empty()){
        sum+=q.front();
        q.pop();
    }
    return sum/n;
}
int main(){
    queue <int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<average(q)<<endl;
}
