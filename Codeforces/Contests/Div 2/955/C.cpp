#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> cards(n);
        for(int i = 0; i<n; i++){
            cin>>cards[i];
        }
        int ans = 0;
        int cur = 0;

        for(int i = 0, window = 0; i<n; i++){
            if(cards[i]>r){ //current can never be bigger
                window = i+1;
                cur = 0;
                continue;
            }
            cur+=cards[i];
            if(cur>=l && cur<=r){
                ans++;
                cur = 0;
                window =  i+1;
            }
            if(cur>r && window<i){
                while(cur>r && window<i) {
                    cur -= cards[window];
                    window++;
                }
                if(cur>=l && cur<=r){
                    ans++;
                    window = i+1;
                    cur = 0;
                }
            }
        }
        if(cur>=l && cur<=r){
            ans++;
        }
        cout<<ans<<"\n";
    }
}
