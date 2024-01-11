#include <iostream>
using namespace std;
//wrapping up the data into a single unit
//ENCAPSULATION
class car{
    private:
    string model="swift";
    public:
    string type;
    int price;
    void model_name_and_type(){
        cout<<"model name:"<<model<<endl;
        cout<<"model type:"<<type<<endl;
    }
};
int main(){
    car c;
    c.type="maruti";
    c.model_name_and_type();
}
