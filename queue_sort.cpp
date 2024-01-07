//basic bubble sort
#include <iostream>
using namespace std;
#include <queue>
void sort(queue <int> q){
    int a[100];
    int k=0;
    while(!q.empty()){
        a[k++]=q.front();
        q.pop();
    }
    for(int i=0;i<k-1;i++){
        for(int j=i;j<k-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=0;i<k;i++){
        q.push(a[i]);
    }
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
    
}
int main(){
    queue <int>q;
    q.push(5);
    q.push(2);
    q.push(3);
    q.push(4);
    sort(q);
}
