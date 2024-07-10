class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string i: logs){
            if(i == "../" ){
                if(ans > 0){
                    ans--;
                }
            }
            if(i[0] != '.'){
                ans++;
            }

        }
        return ans;
    }
};
