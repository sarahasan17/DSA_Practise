#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int a[]={5,1,2,3,7,8};
    int len=sizeof(a)/sizeof(a[0]);
    stack<int> s;
    for(int i=0;i<len;i++){
        if(s.empty()){
            s.push(a[i]);
            continue;
        }
        while(s.empty()==0 && s.top()<a[i]){
            cout<<s.top()<<"-->"<<a[i]<<endl;
            s.pop();
        }
        s.push(a[i]);
    }
}
