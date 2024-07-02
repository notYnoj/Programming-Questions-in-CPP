#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char, vector<int>> nums;
    map<char, int> dp;
    map<char, pair<int, int>> dp2;
    for(int i =0; i<n; i++){
        nums[s[i]].push_back(i);
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        int changes;
        cin>>c>>changes;
        if(changes==n){
            cout<<n<<'\n';
            continue;
        }
        if(n-nums[c].size()<=changes){
            cout<<n<<'\n';
            continue;
        }
        if(dp.find(c) != dp.end()){
            int amnt = dp[c];
            if(changes>amnt){
                int ans = 2+amnt;
                changes-=amnt;
                auto numbers = nums[c];
                

            }else{
                cout<<(changes+(amnt == changes?2:1))<<'\n';
            }
        }else{


        }
    }

}
