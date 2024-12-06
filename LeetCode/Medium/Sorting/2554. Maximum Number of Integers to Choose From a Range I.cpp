class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cur = 0;
        int ptr = 0;
        int tot = 0;
        int m = banned.size();
        sort(banned.begin(), banned.end());
        banned.erase( unique( banned.begin(), banned.end() ), banned.end() );
        for(int i = 1; i<=n; i++){
            if(ptr<m && banned[ptr] == i){
                ptr++;
                continue;
            }else{
                cur+=i;
                tot++;
                if(cur>maxSum){
                    return tot-1;
                }
            }
        }
        return tot;
    }
};
