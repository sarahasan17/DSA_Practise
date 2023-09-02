#include<iostream>
using namespace std;
#include <stack>
int main(){
    stack<char> s;
    int t=0;
    string l="[()]{}{[()()]()}";
    for(int i=0;i<l.length();i++){
        if(l[i]=='[' or l[i]=='(' or l[i]=='{'){
            s.push(l[i]);
        }
        else{
            if(l[i]==']' and s.top()=='['){
                s.pop();
            }
            else if(l[i]==')' and s.top()=='('){
                s.pop();
            }
            else if(l[i]=='}' and s.top()=='{'){
                s.pop();
            }
            else{
                t=1;
                break;
            }
        }
    }
    if(t==0 and s.size()==0){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"Not balanced"<<endl;
    }
}

