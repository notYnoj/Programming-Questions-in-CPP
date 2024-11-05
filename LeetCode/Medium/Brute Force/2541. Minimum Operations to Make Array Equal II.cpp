class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int n = nums1.size();
        vector<int> indx;
        long long pos = 0;
        long long tots = 0;
        for(int i = 0; i<n; i++){
            long long cur = nums1[i] - nums2[i];
            tots+=cur;
            long long z = (cur<0?cur*-1:cur);
            if(cur != 0 && z<k){
                return -1;
            }
            if(k!=0 && cur%k){
                return -1;
            }
            if(cur>0){
                pos+=cur;
            }
            
        }
        if(k == 0){
            if(tots == 0 && pos == 0){
                return 0;
            }else{
                return -1;
            }
        }
        if(tots!=0 || pos%k){
            return -1;
        }else{
            return pos/k;
        }
    }
};
