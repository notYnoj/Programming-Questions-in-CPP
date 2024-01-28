class Solution {
//refer to Codeforces/D/D-Multiplication Table for explanation
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        while(low<high){
            int mid = low + (high-low)/2;
            if(k>x(mid, n, m)){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
private:
    int x(int t, int n, int m){
        int z = 0;
        for(int i = 1; i<=n; i++){
            z+=min(t/i, m);
        }
        return z;
    }
};
