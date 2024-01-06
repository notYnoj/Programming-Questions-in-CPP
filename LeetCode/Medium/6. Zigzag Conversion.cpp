class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        numRows -=1;
        vector<vector<char>> container(numRows+1);
        int cur = 0;
        bool up = true;
        for(int i = 0; i<s.size(); i++){
            container[cur].push_back(s[i]);
            if(up){
                cur++;
                if(cur == numRows){
                    up = false;
                }
            }else{
                cur--;
                if(cur == 0){
                    up = true;
                }
            }
        }
        string t = "";
        for(const auto i: container){
            for(auto j: i){
                t+=j;
            }
        }
        return t;
        
    }
};
