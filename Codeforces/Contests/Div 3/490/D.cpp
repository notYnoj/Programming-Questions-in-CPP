#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m;
    cin >> n >> m;
    ll k = n / m;
    vector<ll> a(n);
    vector<vector<ll>> val(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        val[a[i] % m].push_back(i);
    }
    ll ans = 0;
    vector<pair<ll, ll>> fre;
    for (ll i = 0; i < 2 * m; ++i) {
        ll cur = i % m;
        while (int(val[cur].size()) > k) {
            ll elem = val[cur].back();
            val[cur].pop_back();
            fre.push_back(make_pair(elem, i));
        }
        while (int(val[cur].size()) < k && !fre.empty()) {
            ll elem = fre.back().first;
            ll mmod = fre.back().second;
            fre.pop_back();
            val[cur].push_back(elem);
            a[elem] += i - mmod;
            ans += i - mmod;
        }
    }

    cout << ans << endl;
    for (ll i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
/* TLE CODE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxN = 2e5+5;
ll need[mxN];
//u want equal amounts of remainders
int main(){
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> mods(m, 0);
    vector<ll> arr(n);
    vector<vector<ll>> mp(m+1);
    for(ll i = 0; i<n; i++){
        cin>>arr[i];
        mp[arr[i]%m].push_back(i);
        mods[arr[i]%m]++;
    }
    ll needs = n/m;
    for(ll i = 0; i<m; i++){
        if(mods[i]> needs) {
            need[i] = 1;
        }
    }
    ll ans = 0;
    ll previously_found = 0;
    for(ll i = 0; i<m; i++){
        if(need[i]){
            ll znn = mods[i] - needs;
            ll counter = (i+1>previously_found?1:previously_found-i);
            for(ll j = max(i+1, previously_found) % m; j!=i; (j = (j+1) % m)){
                if(mods[j]<needs){
                    if(needs-mods[j] >=znn){
                        mods[i] = needs;
                        mods[j] += znn;
                        for(ll tz = 0; tz<znn; tz++){
                            ans+=counter;
                            arr[mp[i].back()]+=counter;
                            mp[i].pop_back();
                        }
                        if(mods[j] >= needs) need[j]=true;
                        previously_found = j;
                        break;
                    }else{
                        for(ll tz = 0; tz<(needs-mods[j]); tz++){
                            ans+=counter;
                            arr[mp[i].back()]+=counter;
                            mp[i].pop_back();
                        }
                        znn-=(needs-mods[j]);
                        mods[j] = needs;
                    }
                }
                counter++;
            }
        }
        need[i] = false;
    }

    cout << ans << "\n";
    for (ll i: arr) cout << i << " ";




}
*/
