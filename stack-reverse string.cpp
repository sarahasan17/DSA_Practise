#include <iostream>
#include<stack>
using namespace std;

void reversestring(string a){
    stack<string> s;
    for(int i=0;i<a.length();i++){
        string word="";
        while(a[i]!=' ' && i<a.length()){
            word+=a[i];
            i++;
        }
        s.push(word);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
   string a="My name is Sara";
   reversestring(a);
}
