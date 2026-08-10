//5 6
//1 0
//
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int nt,r;
    cin>>nt>>r;
    string ls = to_string(nt);
    string rs = to_string(r);
    int l = 0;
    int ans = 0;
    while(l < ls.size() && ls[l] == rs[l]){
        l++;
        ans+=2;
    }
    if(l == ls.size()){
        cout<<ans<<'\n';
        return;
    }else{
        //
        if((ls[l]-'0') + 2 <= (rs[l] - '0')){
            cout<<ans<<'\n';
        }else{
            //its 1 above
            ans++;
            l++;
            while(l<rs.size() && (rs[l] == '0' && ls[l] == '9')){
                ans++;
                l++;
            }
            cout<<ans<<'\n';
        }
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        solve();
    }
}
