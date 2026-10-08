#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define nl '\n'
#include <chrono>
using namespace std;
int t;
// Everything Else thats new :D
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T> p){
    os<<p.first<<' '<<p.second<<endl;
    return os;
}
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << ' ';
    }
    return os;
}


template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec){
    //of size n
    for(T& elem: vec){
        is>>elem;
    }
    return is;
}


void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans = LLONG_MAX;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for(int i = 0; i<n; i++){
        ll a,b,c;
        cin>>a>>b>>c;

        if(a == b && b == c){
            ans = min(a+b+c, ans);
        }else{
            if(a <= b && b <= c){
                ll extra = 2 * (min(b-a, c-b) + 1);
                pq.push({a+b+c, extra});
            }else{
                pq.push({a+b+c, 0});
            }
        }
    }

    vi diff, cost;
    while(!pq.empty()){
        pll tz = pq.top();
        diff.pb(tz.first);
        cost.pb(tz.second);
        pq.pop();
    }

    if(diff.empty()){
        cout<<ans<<nl;
        return;
    }

    ll l = 0;
    while(true){
        // Cannot raise the minimum beyond an all-equal triple.
        if(diff[l] >= ans){
            cout<<ans<<nl;
            return;
        }

        // Extra operations needed before this triple's sum can grow.
        if(k < cost[l]){
            cout<<min(diff[l], ans)<<nl;
            return;
        }
        k -= cost[l];

        if(l == (ll)diff.size()-1){
            ll mx2 = k / (l+1);
            cout<<min(diff[l]+mx2, ans)<<nl;
            return;
        }else{
            ll cur = diff[l];
            ll nxt = diff[l+1];

            if((nxt-cur) * (l+1) <= k){
                k -= (nxt-cur) * (l+1);
                l++;
            }else{
                ll mx2 = k / (l+1);
                cout<<min(diff[l]+mx2, ans)<<nl;
                return;
            }
        }
    }
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    cin>>t;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
