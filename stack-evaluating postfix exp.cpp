#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string a="231*+9-";
    stack<char> s;
    int res;
    for(int i=0;i<a.length();i++){
        if(a[i]>='0' && a[i]<='9'){
            s.push(a[i]);
        }
        else{
            int num1=s.top()- '0';
            s.pop();
            int num2=s.top()-'0';
            s.pop();
            if(a[i]=='-'){
                res=num1-num2;
            }
            else if(a[i]=='+'){
                res=num1+num2;
            }
            else if(a[i]=='/'){
                res=num1/num2;
            }
            else if(a[i]=='*'){
                res=num1*num2;
            }
            char r1='0'+res;
            s.push(r1);
        }
    }
    cout<<s.top()<<endl;
}
