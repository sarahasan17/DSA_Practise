#include <iostream>
using namespace std;
//inherit attributes and properties of a class
//INHERITANCE
class animal{
    public:
    string type;
    int legs;
    string eating_habit;
    animal(string animal_type, int animal_legs, string animal_eating_habit)
        : type(animal_type), legs(animal_legs), eating_habit(animal_eating_habit) {
    }
};
class dog:public animal{
    int age=3;
    public:
    dog(string dog_type, int dog_legs, string dog_eating_habit, int dog_age)
        : animal(dog_type, dog_legs, dog_eating_habit), age(dog_age) {
    }
    void display_det(){
        cout<<"type:"<<type<<endl;
        cout<<"legs:"<<legs<<endl;
        cout<<"eating_habit:"<<eating_habit<<endl;
        cout<<"age:"<<age<<endl;
    }
};


int main(){
    dog d=dog("husky",4,"non-veg",3);
    d.display_det();
}
