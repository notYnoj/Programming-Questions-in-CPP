#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 2e5 +5;
ll dp[mxN][10];
int main(){
    int n;
    cin>>n;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<10; j++){
            dp[i][j] = LLONG_MIN; //changed form -9999999 thanks for the edit linnrue!
        }
    }
    dp[0][0] = 0;
 
    for(int i = 1; i<=n; i++){
        int k;
        cin>>k;
        vector<ll> one; //was int, if its int it gets overflow which is strange but ty for edit linnrue!
        int two = -1;
        int three = -1;
        for(int j= 0; j<k; j++){
            int cost, damage;
            cin>>cost>>damage;
            if(cost>=3){
                three = max(damage, three);
            }
            else if(cost>=2){
                two = max(damage, two);
                three = max(damage,three);
            }else{
                three = max(damage, three);
                one.push_back(damage);
            }
        }
        sort(one.rbegin(), one.rend());
        for(int mods = 0; mods<10; mods++){
            if(one.size()>=3) {
                if (mods + 3 > 9) {
                    ll ans = one[0] * 2;
                    for (int temp = 1; temp < 3; temp++) {
                        ans += one[temp];
                    }
                    dp[i][(mods + 3) % 10] = max(dp[i][(mods + 3) % 10], dp[i - 1][mods] + ans);
                } else {
                    ll ans = one[0];
                    for (int temp = 1; temp < 3; temp++) {
                        ans += one[temp];
                    }
 
                    dp[i][(mods + 3) % 10] = max(dp[i][(mods + 3) % 10], dp[i - 1][mods] + ans);
                }
            }
            if(one.size()>=2 || (two != -1 && !one.empty())) {
                if (mods + 2 > 9) {
                    if (one.size() == 1) {
                        ll ans = (two>one[0]?2*two+one[0]: 2*one[0]+two);
                        dp[i][(mods+2)%10] = max(dp[i][(mods+2)%10], dp[i-1][mods]+ans);
 
                    } else {
                        ll ans;
                        if(two>one[0]){
                            ans = 2*two+one[0];
                        }else{
                            if(two>one[1]){
                                ans = 2*one[0]+two;
                            }else{
                                ans = 2*one[0]+one[1];
                            }
                        }
                        dp[i][(mods+2)%10] = max(dp[i][(mods+2)%10], dp[i-1][mods]+ans);
                    }
                } else {
                    if (one.size() == 1) {
                        ll ans = one[0]+two;
                        dp[i][(mods+2)%10] = max(dp[i][(mods+2)%10], dp[i-1][mods]+ans);
                    } else {
                        ll ans;
                        if(two>one[0]){
                            ans = two+one[0];
                        }else{
                            if(two>one[1]){
                                ans = two+one[0];
                            }else{
                                ans = one[1]+one[0];
                            }
                        }
                        dp[i][(mods+2)%10] = max(dp[i][(mods+2)%10], dp[i-1][mods]+ans);
                    }
                }
 
            }
            if(mods+1>9){
                ll ans = three*2;
                assert(ans>0);
 
                dp[i][(mods+1)%10] = max(dp[i][(mods+1)%10], dp[i-1][mods]+ans);
            }else{
                ll ans = three;
                assert(ans>0);
 
                dp[i][(mods+1)%10] = max(dp[i][(mods+1)%10], dp[i-1][mods]+ans);
            }
            dp[i][mods] = max(dp[i][mods], dp[i-1][mods]);
 
        }
    }
 
    ll ans = 0;
    for(int i = 0; i<10; i++){
        ans = max(ans, dp[n][i]);
    }
 
 
    cout<<ans;
}
