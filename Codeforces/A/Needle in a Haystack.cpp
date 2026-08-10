#include <bits/stdc++.h>

using namespace std;
void solve(){
    string s, t;
    cin>>s>>t;
    vector<int> count(26, 0);
    vector<int> countT(26, 0);
    for(int i = 0; i<s.size(); i++){
        count[s[i] - 'a']++;  
    }
    for(int i = 0; i<t.size(); i++){
        countT[t[i]-'a']++;
    }
    for(int i = 0; i<26; i++){
        if(count[i] > countT[i]){
            cout<<"Impossible\n";
            return;
        }
        countT[i] -= count[i];
    }
    string ans = "";
    int l = 0;
    vector<pair<int, int>> ins;
    int extraPtr = 0;
    for (int k = 0; k < (int)s.size(); k++) {
        int target = s[k] - 'a';
        while (extraPtr < target) {
            if (countT[extraPtr] > 0) ins.push_back({extraPtr, countT[extraPtr]});
            countT[extraPtr] = 0;
            extraPtr++;
        }
        ins.push_back({target, 1}); // s[k] itself
    }
    while (extraPtr < 26) {
        if (countT[extraPtr] > 0) ins.push_back({extraPtr, countT[extraPtr]});
        extraPtr++;
    }
    for(const auto& [cur_char, amount] : ins){
        char c = 'a'+cur_char;
        ans+=string(amount, c);
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
//surgical fix </3
