class CustomStack {
public:
    vector<int> a;
    int ptr = 0;
    int mx;

    CustomStack(int maxSize) {
        mx = maxSize;
        a.resize(maxSize);
    }
    
    void push(int x) {
        if(ptr+1<=mx){
            a[ptr++] = x;
        }
    }
    
    int pop() {
        if(ptr == 0){
            return -1;
        }else{
            return a[--ptr];
        }
    }
    
    void increment(int k, int val) {
        x
        for(int i = 0; i<k; i++){
            if(i>=ptr){
                break;
            }
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
