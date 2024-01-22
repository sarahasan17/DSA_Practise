#include <iostream>
#include <vector>
#include <queue>
using namespace std;
double getmedian(priority_queue <int> s,priority_queue<int,vector<int>,greater<int>> g){
    if(s.size()==g.size()){
        return (double)(s.top()+g.top())/2.0;
    }
    else{
        return s.top();
    }
}
int main(){
    vector<double> ans;
    vector<int> a={1,7,3,4,2,5,6};
    priority_queue <int> s;
    priority_queue<int,vector<int>,greater<int>> g;
    s.push(a[0]);
    ans.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        int m=a[i];
        if(s.size()>g.size()){
            if(m<s.top()){
                g.push(s.top());
                s.pop();
                s.push(m);
            }
            else{
                g.push(m);
            }
        }
        else{
            if(m<s.top()){
                s.push(m);
            }
            else{
                g.push(m);
                s.push(g.top());
                g.pop();
            }
        }
        ans.push_back(getmedian(s,g));
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}

