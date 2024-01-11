#include <iostream>
using namespace std;
//one name many forms
//POLYMORPHISM
class animal{
    public:
    void sum(int a,int b){
        cout<<"sum of the integers:"<<(a+b)<<endl;
    }
    void sum(string a,string b){
        string c=a+b;
        cout<<"sum of the strings:"<<c<<endl;
    }
};
int main(){
    animal a;
    a.sum(1,2);
    a.sum("blue","stone");
}
