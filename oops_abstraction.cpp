#include <iostream>
using namespace std;
//process of keeping the required details only and not the process not required
class data{
    public:
    //the process has been hidden
    void sum(int x,int y){
        int a=x;
        int b=y;
        int c=a+b;
        cout<<"sum:"<<c<<endl;
    }
};
int main()
{
    data d;
    int x=5;
    int y=6;
    //the output needed is shown
    d.sum(5,6);
}
