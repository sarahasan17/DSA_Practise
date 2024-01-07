#include <iostream>
using namespace std;
#include <queue>
int nthelement(queue <int> q,int i){
    while(i!=1){
        q.pop();
        i--;
    }
    return q.front();
}
int main(){
    queue <int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<nthelement(q,4)<<endl;
}
