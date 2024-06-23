#include <iostream>
#include <stack>
using namespace std;

void sortedstack(stack<int>& s,int x){
    if(s.empty() || s.top()<x){
        s.push(x);
        return;
    }
    int a=s.top();
    s.pop();
    sortedstack(s,x);
    s.push(a);
}
void sort(stack<int>& s){
    if(s.empty()){
        return;
    }
    int a=s.top();
    s.pop();
    sort(s);
    sortedstack(s,a);
}
void display(stack<int>& s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(4);
    s.push(0);
    sort(s);
    display(s);
}
