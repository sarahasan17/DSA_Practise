#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack <int> &s){
    if(s.empty()){
        return;
    }
    int a=s.top();
    s.pop();
    sort_stack(s);
    stack <int> t;
    while(!s.empty() && s.top()<a){
        t.push(s.top());
        s.pop();
    }
    s.push(a);
    while(!t.empty()){
        s.push(t.top());
        t.pop();
    }
    
}
int main()
{
    int arr[10];
    stack <int> s;
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
        s.push(arr[i]);
    }
    sort_stack(s);
    cout<<"Elements of the array are:"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
