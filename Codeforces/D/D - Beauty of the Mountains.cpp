#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<ll>> grid(n, vector<ll>(m));
        vector<vector<ll>> needed(n, vector<ll>(m));
        ll mon1 = 0, mon2 = 0;
        for(ll i = 0;i<n; i++){
            for(ll j = 0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        for(ll i = 0 ;i<n; i++){
            string s;
            cin>>s;
            for(ll j = 0; j<m; j++) {
                if (s[j] == '1') {
                    mon1 += grid[i][j];
                    needed[i][j] = 1;
                } else {
                    mon2 += grid[i][j];
                    needed[i][j] = 0;
                }
            }
        }

        if(k == 1 || mon1 == mon2) cout<<"YES\n";
        else{
            //kxk -check, check will be for wihtout them, with them will be kxk-check
            set<ll> st;
            vector<vector<ll>> pref(n, vector<ll>(m, 0));
            for(ll i = 0; i<n; i++){
                for(ll j = 0; j<m; j++){
                    pref[i][j] = needed[i][j];
                    if(i>0){
                        pref[i][j]+=pref[i-1][j];
                    }
                    if(j>0){
                        pref[i][j]+=pref[i][j-1];
                    }
                    if(i>0 && j>0){
                        pref[i][j] -= pref[i-1][j-1];
                    }
                }
            }
            //pfs in 2d
            for(ll i = 0; i<=n-k; i++){
                for(ll j = 0; j<=m-k; j++){
                    ll cur = pref[i+k-1][j+k-1];
                    if(i>0) cur-= pref[i-1][j+k-1];
                    if(j>0) cur-=pref[i+k-1][j-1];
                    if(i>0 && j>0) cur+=pref[i-1][j-1];
                    st.insert(cur);
                }
            }
            //kxk is equal to that pretty obvious why! (overcounting also! principle of inclusivity and exclusivivity!!)
            vector<bool> used((k*k+1), false);
            ll totz = k*k;
            //the math stuff yk the buiz
            bool can = false;
            ll gcd = LLONG_MAX;
            ll df = max(mon1,mon2)-min(mon1,mon2);
            for(ll i: st){
                if(used[totz-i] || used[totz]) continue;
                else{
                    ll ax = totz-i;
                    ll bx = i;
                    ll newx = max(ax,bx)-min(ax,bx);
                    if(!newx) continue;
                    if (gcd == LLONG_MAX) gcd = newx;
                    else gcd = __gcd(gcd, newx);
                    if((df%newx) == 0){
                        cout<<"YES\n";
                        can = true;
                        break;
                    }
                    if(df%gcd == 0){ //REMEBER THAT GCD IS COMMMUNIVITVE AND THE ONLY WAY TO SOLVE EQUATION OF THE FORM ax+by+cd = T must be for gcd(a,b,c) to divide T
                        cout<<"YES\n";
                        can = true;
                        break;
                    }
                }
            } //REMMEBER SOLVING THAT Linear Diophantine FRFR also math stuff! it can be negative and it odesnt matter since % is like abs!
            if(can) continue;
            else{
                if(df % gcd == 0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }

        }
    }
}
