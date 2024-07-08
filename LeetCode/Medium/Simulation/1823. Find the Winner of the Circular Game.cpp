class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k == 1){
            return n;
        }
        vector<int> hold(n); 
        vector<int> used(n,0);
        iota(hold.begin(), hold.end(), 1);
        int ptr = 0;
        for(int i =0; i<n-1; i++){
            for(int i =0; i<k; i++){
                ptr++;
                ptr%=n;
                while(used[ptr]){
                    ptr++;
                    ptr%=n;
                }
            }
            used[ptr] = 1;
        }
        for(int i = 0; i<n; i++){
            if(!used[i]) return (--hold[i] == 0?n:hold[i]);
        }
        return -1;
    }
};
