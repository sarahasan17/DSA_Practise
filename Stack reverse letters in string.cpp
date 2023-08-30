#include <iostream>
#include<stack>
using namespace std;

void reversestring(string a){
    stack<char> s;
    for(int i=0;i<a.length();i++){
        char word;
        while(a[i]!=' ' && i<a.length()){
            s.push(a[i]);
            i++;
        }
        while(!s.empty()){
        cout<<s.top();
        s.pop();
        }
        cout<<" ";
    }

}

int main(){
   string a="My name is Sara";
   reversestring(a);
}
