#include <iostream>
#include <stack>
using namespace std;

int pref(char a){
    if(a=='*' || a=='/'){
        return 3;
    }
    else if(a=='-' || a=='+'){
        return 2;
    }
    else{
        return 1;
    }
}
int main(){
    string a="(A-B)*[C/(D+E)+F]";
    stack<char> s;
    stack<char> t;
    t.push('#');
    for(int i=0;i<a.length();i++){
        if(isalpha(a[i])){
            s.push(a[i]);
        }
        else if(a[i]=='*' || a[i]=='+' || a[i]=='/' || a[i]=='-'){
            if(pref(t.top())<pref(a[i]) || t.top()=='[' || t.top()=='(' || t.top()=='{'){
                t.push(a[i]);
            }
            else{
                while(pref(a[i])<=pref(t.top())){
                    s.push(t.top());
                    t.pop();
                }
            }
        }
        else{
            if(a[i]=='[' || a[i]=='(' || a[i]=='{'){
                t.push(a[i]);
            }
            else if(a[i]==')' || a[i]=='}' || a[i]==']'){
                while(t.top()!='[' && t.top()!='{' && t.top()!='('){
                    s.push(t.top());
                    t.pop();
                }
                t.pop();
            }
        }
    }
    while(t.top()!='#'){
        s.push(t.top());
        t.pop();
    }
    while(!s.empty()){
        t.push(s.top());
        s.pop();
    }
    while(t.top()!='#'){
        cout<<t.top()<<" ";
        t.pop();
    }
}
