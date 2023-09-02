#include<iostream>
#include <stack>
using namespace std;
int main(){
    stack<char> s;
    string word="sara";
    for(int i=0;i<word.length();i++){
        s.push(word[i]);
    }
    for(int i=0;i<word.length();i++){
        cout<<s.top();
        s.pop();
    }
}
