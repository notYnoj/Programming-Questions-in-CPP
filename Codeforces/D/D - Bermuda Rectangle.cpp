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
    ll s, q;
    cin>>s>>q;
    //we can form factor pairs
    //let height be f1 and width f2
    //then the answer is going to be
    //7
    //1 16 (1-1) = 16
    //2 8 (2-2) = 8
    //4 4 (3-4) = 4
    //8 2 (5-8) = 2
    //16 is 1 (9-16) = 1
    vi factors;
    for(ll i = 1; i*i<=s; i++){
        if(s%i == 0){
            factors.pb(i);
            factors.pb(s/i);
        }
    }
    sort(all(factors));
    //lower_bound() find x's smallest factor touched then do pref[factor] - 
    vi pref(factors.size(), 0);
    pref[0] = s;
    for(ll i = 1; i<factors.size(); i++){
        pref[i] = (s/factors[i])*(factors[i] - factors[i-1])  + pref[i-1];
    }
    //ans = totz - (s/fac)* (fac - x)

    // 1 2 3 4 6 12
    //x =3 , y =3 
    //
    //1 2 3 6
    //6 + 3 
    for(ll i =0; i<q; i++){
        ll ans = 0;
        ll x, y;
        cin>>x>>y;
        //for int i = 1 - x i+= min(y, s/x);
        //note that at most n at big numbers can have sqrt(n) factors
        ll facIdx = (lower_bound(all(factors), y) - factors.begin());
        //first one where 8/3 = 2 want first one where s/x is for sure bigger than x thus making it so that we will for sure have to take pref sum
        ll fac2Idx = (upper_bound(all(factors), s/x) - factors.begin());
        ll fac = *lower_bound(all(factors), y);
        ll fac2 = *lower_bound(all(factors), s/x);
        if(fac2Idx> facIdx){
            cout<<(x*y)<<nl;
            continue;
        }
        //12 
        ll totz = pref[facIdx];
        //consider liek sutbracting everything underneat where we know there at least x tehn everything else  becomes x
        totz  -= (pref[fac2Idx == 0 ? 0 : fac2Idx-1]);
        totz += (x * (fac2Idx == 0 ? factors[0] : factors[fac2Idx-1]));
        //now there can still be stuff above and this is simply determined by y

        //if 16
        //this uses sqrt(n) * q which is bad
        //we can do sqrt(n) +
        //idea is to use pref sums
        //consider where y is dominating
        //y dominates where num/factor>=y
        //so we must find first factor where num/y>=factor
        //from here on out we get pref[biggest below x] - pref[factor] + y * (factor - 1)
        //12 
        //6 3
        // 
        ans+=totz;
        ans-=((s/fac) * (fac-y));
        cout<<ans<<nl;
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
