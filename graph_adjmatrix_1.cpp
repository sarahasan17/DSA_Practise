#include<iostream>
#include<list>
using namespace std;
class graph{
    public:
    list<int> *l;
    int v;
    graph(int ver){
        v=ver;
        l=new list<int>[v];
    }
    void connect(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printadjmatrix(){
        for(int i=0;i<v;i++){
            cout<<"vertex "<<i<<"-->";
            for(int g:l[i]){
                cout<<g<<' ';
            }
            cout<<endl;
        }
    }
};
int main(){
    graph g(4);
    g.connect(0,2);
    g.connect(1,2);
    g.connect(3,2);
    g.printadjmatrix();
}
