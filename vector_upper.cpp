#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<string> a;
    a={"sara","is","a","good","girl"};
    for(int i=0;i<a.size();i++){
        a[i][0]=toupper(a[i][0]);
    }
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
}
