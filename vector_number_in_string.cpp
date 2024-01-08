#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> numberinstring(vector<string> a){
    vector<string> b;
    for(int i=0;i<a.size();i++){
        int t=0;
        for(int j=0;j<a[i].length();j++){
            if(a[i][j]>='0' && a[i][j]<='9'){
                t=1;
                break;
            }
        }
        if(t==1){
            b.insert(b.end(),a[i]);
        }
    }
    return b;
}
int main(){
    vector<string> a;
    a={"sara12","montu","1amma","abbu8"};
    vector<string> b;
    b=numberinstring(a);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<' ';
    }
}
