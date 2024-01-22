#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class data{
    public:
    int val;
    int be;//index of the vector
    int af;//index of the vector inside the vector
    data(int v,int b,int a){
        val=v;
        be=b;
        af=a;
    }
};

struct mydata{
    bool operator()(data &d,data &d2){
        return d.val>d2.val;
    }
};
int main(){
    vector<int> ans;
    vector<vector<int>> a={{1,2,5},{3,6},{4,8,9}};
    priority_queue<data,vector<data>,mydata> q;
    for(int i=0;i<3;i++){
        data d(a[i][0],i,0);
        q.push(d);
    }
    while(!q.empty()){
        data m=q.top();
        q.pop();
        int b=m.be;
        int ab=m.af;
        ans.push_back(m.val);
        if(ab<a[b].size()-1){
            data d4(a[b][ab+1],b,ab+1);
            q.push(d4);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}

