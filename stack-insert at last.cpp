#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack <int> s, int a){
    stack <int> t;
    while(s.empty()!=true){
        t.push(s.top());
        s.pop();
    }
    t.push(a);
    while(t.empty()!=true){
        cout<<t.top()<<endl;
        s.push(t.top());
        t.pop();
    }
    while(s.empty()!=true){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
   stack <int> s;
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   insertAtBottom(s,1);
   
}
