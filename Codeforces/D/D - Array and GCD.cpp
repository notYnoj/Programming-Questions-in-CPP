#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
    
namespace IO {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem;
        }
        return os;
    }
}
using namespace IO;

vi primes;
const int mxN = 4e5+5;
const int N = 6e6;
ll pref[mxN];
bool found[N+1];
void sieve(){
    fill(found, found+N+1, true);
    for(int p = 2; p*p<=N; p++){
        if(found[p]){
            for(int i = p*p; i<=N; i+=p){
                found[i] = false;
            }
        }
    }
    for(int i =2; i<=N; i++){
        if(found[i])primes.pb(i);
    }
}
void prefix(){
    pref[0] = primes[0] - 2; 
    for(int i = 1; i<mxN; i++){
        pref[i] = pref[i-1] + primes[i] - 2;
    }
}
void precomp(){
    sieve();
    prefix();
}

void solve(int t){
    int n;
    cin>>n;
    vi a(n);
    int coins = 0;
    for(int i = 0; i<n; i++){cin>>a[i]; coins+=a[i]-2;}
    sort(all(a));
    if(pref[n-1]<=coins){
        cout<<0<<endl;
    }else{
        int ptr = 0;
        while(true){
            ptr++;
            coins-=(a[ptr-1] -2);
            if(coins>=pref[n-1-ptr]){
                cout<<ptr<<endl;
                break;
            }
        }
    }
    


}
int main(){
    int t;
    cin>>t;
    precomp();
    while(t--){
        solve(t);
    }

}
