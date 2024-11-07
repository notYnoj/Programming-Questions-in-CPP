class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> a(32, 0);
        for(int i: candidates){
            int count = 0;
            while(i>0){
                a[count]+=(i%2?1:0);
                i = i>>1;
                count++;
            }

        }

        return *max_element(a.begin(), a.end());
    }
};
