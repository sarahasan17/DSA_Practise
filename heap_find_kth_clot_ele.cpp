using namespace std;
#include <vector>
#include <queue>
//pair for priority queue like (2,1),(1,2),(0,3),(1,4),(2,5)
int main(){
    vector<int> a={1,2,3,4,5};
    int x=3;
    int k=4;
    priority_queue<pair<int,int>> pq;
    for(auto ele: a){
        pq.push(make_pair(abs(x-ele),ele));
        if(pq.size()>k){
            pq.pop();
        }
    }
    priority_queue<int> ans;
    while(!pq.empty()){
        ans.push(-pq.top().second);
        pq.pop();
    }
    while(!ans.empty()){
        cout<<-ans.top()<<" ";
        ans.pop();
    }
}
