class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> mp;
        map<char, int> hsh;
        for(int i = 0; i<s.size(); i++){
            hsh[s[i]]++;
        }
        for(auto i:hsh){
            mp.push_back({i.second, i.first});
        }
        sort(mp.begin(), mp.end(), greater<>());
        string f = "";
        for(int i = 0; i<mp.size(); i++){
            for(int j = 0; j<mp[i].first; j++){
                f+=mp[i].second;
            }
        }
        return f;

    }
};
