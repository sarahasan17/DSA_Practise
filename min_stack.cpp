class MinStack {
    int *a;
    int t;
public:
    MinStack() {
        a=new int[10000000];
        t=-1;
    }
    
    void push(int val) {
        t++;
        a[t]=val;
    }
    
    void pop() {
        t--;
    }
    
    int top() {
        return a[t];
    }
    
    int getMin() {
        int min=2147483647;
        for(int i=0;i<=t;i++){
            if(min>a[i]){
                min=a[i];
            }
        }
        return min;
    }
};
