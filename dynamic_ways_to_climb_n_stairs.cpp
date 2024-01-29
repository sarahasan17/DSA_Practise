#include <iostream>
using namespace std;
//dynamic programming: eg:cound total no. of way, count best way, count the no. of ways
//try to represent the problem in terms of index
//do all possible stuffs wrto the problem statemnt
//if it says find the sum then find the sum or if it says fin min then find the min
int dynamic_steps(int n){
    if(n==1 || n==0){
        return 1;
    }
    int left=dynamic_steps(n-1);
    int right=dynamic_steps(n-2);
    return left+right;
}
int main()
{
    int n=dynamic_steps(2);
    cout<<"The possible ways to climb 4 stair:"<<n<<endl;
}
