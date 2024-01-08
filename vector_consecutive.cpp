#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool check(vector<int> a){
    sort(a.begin(),a.end());
    int t=1;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]!=a[i+1]-1){
            t=0;
            break;
        }
    }
    if(t==0){
        return false;
    }
    return true;
}

int main(){
    vector<int> a;
    for(int i=0;i<5;i++){
        int b;
        cin>>b;
        a.insert(a.end(),b);
    }
    cout<<check(a)<<endl;
}
