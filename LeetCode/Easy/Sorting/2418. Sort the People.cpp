class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> s(heights.size());
        for(int i = 0; i<heights.size(); i++){
            s[i] = {heights[i], names[i]};
        }
        sort(s.begin(), s.end());
        vector<string> ans;
        for(int i = heights.size()-1; i>=0; i--){
            ans.push_back(s[i].second);
        }
        return ans;
    }
};
