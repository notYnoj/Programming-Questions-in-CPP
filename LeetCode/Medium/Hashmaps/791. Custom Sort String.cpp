class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> hsh;
        int l = 0;
        for(char i: order){
            hsh[i] = l;
            l++;
        }
        int n = order.size();
        vector<vector<char>> hold2(n);
        string ans = "";
        vector<char> hold;
        for(char i: s){
            if(hsh.find(i)!= hsh.end()){
                hold2[hsh[i]].push_back(i);
            }else{
                hold.push_back(i);
            }
        }
        for(auto i: hold2){
            if(!i.empty()){
                for(char o: i){
                    ans+=o;
                }
            }
        }
        for(char i: hold){
            ans+=i;
        }
        return ans;
    }
};
//spam hashmaps
