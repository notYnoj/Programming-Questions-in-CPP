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
    ll n;
    cin>>n;
    vi a(n);
    cin>>a;
    sort(all(a));
    priority_queue<ll> q;
    long long alice = 0;
    ll bob = 0;
    ll s = 0;
    for(ll i = 0; i<n; ){
        if(a[i] % 2){
            //into q
            ll num = a[i];
            ll c = 0;
            while(i<n && num == a[i]){
                c++;
                s+=( a[i]-1 );
                i++;
            }
            q.push(c);
        }else{
            s+=a[i];
            i++;
        }
    }
    alice+= (s/2);
    bob+= (s/2);
    bool flag = true;
    while(!q.empty()){
        if(flag){
            alice+=q.top();
            flag = false;
        }else{
            bob+=q.top();
            flag = true;
        }
        q.pop();
    }
    cout<<alice<<' '<<bob<<'\n';
    
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
