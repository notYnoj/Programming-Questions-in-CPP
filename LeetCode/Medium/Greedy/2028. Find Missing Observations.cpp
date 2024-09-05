class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int tz = m+n;
        int new_mean = mean*tz;
        for(int i: rolls){
            new_mean-=i;
        }
        if(new_mean<n || 6*n<new_mean){
            return {};
        }
        vector<int> ans(n);
        int ptr = 0;
        int ptr2 = -1;
        cout<<new_mean;
        for(int i = 0; i<n; i++){
            if(new_mean<=6){
                ans[i] = new_mean;
                ptr2 = i;
                break;
            }else{
                ans[i]  = 6;
                new_mean-=6;
            }
        }
        for(int i = ptr2+1; i<n; i++){
            if(ans[ptr] == 1){
                ptr++;
            }
            ans[i] = 1;
            ans[ptr]--;
        }
        return ans;

    }
};
