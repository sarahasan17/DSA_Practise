#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int c=s.size();
    int i=0;
    while(i<(c-1)/2){
        s.pop();
        i++;
    }
    cout<<"middle element:"<<s.top()<<endl;
}

