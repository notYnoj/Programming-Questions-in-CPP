class Solution {
//haha no codeforces or usaco for a bit now :(( ive been busy with work (8 hour shifts are sad but we gotta do what we gotta do frfr food isnt free smh)
//will def get a few down this wednesday and thursday when i dont work :D
public:
    int minimumPushes(string word) {
        int amount = 0;
        map<char, int> mp;
        //8?
        vector<pair<int, char>> st;
        for(const char& i: word){
            mp[i]++;
        }
        for(auto i = mp.begin(); i!=mp.end(); i++){
            st.push_back({i->second, i->first});
        }
        sort(st.begin(), st.end(), greater<pair<int,char>>());
        for(int i = 0; i<st.size(); i++){
            cout<<st[i].first<<" "<<st[i].second<<'\n';
        }
        int z = 1;
        int nums = 8;
        for(int i = 0; i<st.size(); i++){
            amount+=st[i].first*z;
            nums--;
            if(nums == 0){
                z++;
                nums = 8;
            }
        }
        return amount;
    }
};
