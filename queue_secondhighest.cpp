#include <iostream>
using namespace std;
#include <queue>
int secondhighest(queue <int> q){
    int max=-1;
    int max2=-1;
    while(!q.empty()){
        if(q.front()>max){
        max2=max;
        max=q.front();
    }
    else if(q.front()>max2){
        max2=q.front();
    }
    q.pop();
    }
    return max2;
}
int main(){
    queue <int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<secondhighest(q)<<endl;
}
