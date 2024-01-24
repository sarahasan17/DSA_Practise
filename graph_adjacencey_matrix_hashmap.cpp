#include<iostream>
#include<list>
#include <unordered_map>
using namespace std;
class graph{
    unordered_map<string,list<pair<string,int>>> l;
    public:
    void addedge(string x,string y,bool bid,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bid==true){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printval(){
        for(auto a:l){
            cout<<"Vector "<<a.first<<"-->";
            for(auto b:a.second){
                cout<<b.first<<' '<<b.second<<',';
            }
            cout<<endl;
        }
    }
};
int main(){
    graph g;
    g.addedge("A","B",true,20);
    g.addedge("B","C",false,10);
    g.addedge("C","A",false,5);
    g.printval();
}
