#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool balance(string a){
    vector <char> b;
    for(int i=0;i<a.length();i++){
        if(a[i]=='(' || a[i]=='[' || a[i]=='{'){
            b.insert(b.begin(),a[i]);
        }
        else{
            if(a[i]==')' and b[0]=='('){
                b.erase(b.begin());
            }
            else if(a[i]==']' and b[0]=='['){
                b.erase(b.begin());
            }
            else if(a[i]=='}' and b[0]=='{'){
                b.erase(b.begin());
            }
            else{
                return 0;
            }
        }
    }
    if(b.size()==0){
        return 1;
    }
    return 0;
}
int main(){
    string a="{[{}]()}";
    cout<<balance(a)<<endl;
}
