class MyCircularDeque {
public:
    deque<int> gquiz;
    int z;
    MyCircularDeque(int k) {
        z = k;
    }
    
    bool insertFront(int value) {
        if(gquiz.size()<z){
            gquiz.push_front(value);
            return true;
        }else{
            return false;
        }
    }
    
    bool insertLast(int value) {
        if(gquiz.size()<z){
            gquiz.push_back(value);
            return true;
        }else{
            return false;
        }
    }
    
    bool deleteFront() {
        if(gquiz.empty()){
            return false;
        }else{
            gquiz.pop_front();
            return true;
        }
    }
    
    bool deleteLast() {
        if(gquiz.empty()){
            return false;
        }else{
            gquiz.pop_back();
            return true;
        }
    }
    
    int getFront() {
        if(gquiz.empty()){
            return -1;
        }else{
            return gquiz.front();
        }
    }
    
    int getRear() {
        if(gquiz.empty()){
            return -1;
        }else{
            return gquiz.back();
        }
    }
    
    bool isEmpty() {
        if(gquiz.empty()){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(gquiz.size() == z){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
