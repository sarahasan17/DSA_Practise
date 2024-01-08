#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> a;
    for(int i=0;i<4;i++){
        cout<<"Insert the element of the "<<(i+1)<<" vector element "<<endl;
        vector<int> t;
        for(int j=0;j<2;j++){
            int c;
            cin>>c;
            t.insert(t.end(),c);
        }
        a.insert(a.end(),t);
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    
}
