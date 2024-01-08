#include<vector>
using namespace std;

vector<int> strictly(vector <int> a){
    vector <int> b;
    for(int i=1;i<a.size()-1;i++){
        if(a[i-1]>a[i] && a[i+1]>a[i]){
            b.insert(b.end(),a[i]);
        }
    }
    return b;
}

int main(){
    vector<int> a;
    for(int i=0;i<5;i++){
        int b;
        cin>>b;
        a.insert(a.end(),b);
    }
    vector<int> b;
    b=strictly(a);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<' ';
    }
}
