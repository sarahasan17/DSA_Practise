#include <iostream>
using namespace std;
#include <queue>
void removeduplicates(queue <int> q){
    int unique[100];
    int j=0;
    while(!q.empty()){
        int t=q.front();
        int k=0;
        if(j>0){
            for(int i=0;i<j;i++){
            if(t==unique[i]){
                k=1;
                break;
            }
        }
        }
        if(k==0){
            unique[j]=t;
            j++;
        }
        q.pop();
    }
    for(int i=0;i<j;i++){
        q.push(unique[i]);
    }
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
    q.push(2);
    removeduplicates(q);
}
