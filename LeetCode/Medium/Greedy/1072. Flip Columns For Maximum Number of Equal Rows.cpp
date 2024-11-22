class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //want the number of rows that have the same patter aab or such
        map<string, int> mp;
        for(auto i: matrix){
            int a = -1;
            int b = -1;
            string s = "";
            for(int j: i){
                if(a == -1 || j == a){
                    a = j;
                    s+="a";
                }else if(b == -1 || j == b){
                    b = j;
                    s+="b";
                }else{
                    s+=(j == a?"a":"b");
                }
            }
            mp[s]++;
        }
        int mx = 0;
        for(auto i: mp){
            mx = max(mx, i.second);
        }
        return mx;
    }
};
