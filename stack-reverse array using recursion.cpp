#include <iostream>
#include <stack>
using namespace std;
void insert_at_bottom(stack <int> s, int a){
    if(s.size()==0){
        s.push(a);
    }
    else{
        int x=s.top();
        s.pop();
        insert_at_bottom(s,a);
        s.push(a);
    }
}
void reverse(stack <int> s){
    if(!s.empty()){
        int a=s.top();
        s.pop();
        reverse(s);
        insert_at_bottom(s,a);
    }
}
void display(stack <int> s){
    cout<<"Elements of the array are:"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    int arr[10];
    stack <int> s;
    cout<<"Enter the elements of the array:"<<endl;
    for(int i=0;i<10;i++){
        cin>>arr[i];
        s.push(arr[i]);
    }
    reverse(s);
    display(s);
}
