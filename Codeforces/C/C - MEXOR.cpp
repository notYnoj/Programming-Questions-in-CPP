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
    int n,k;
    cin>>n>>k;
    //consider waht happens. hte biggest bit of n cannot be biggeer
    int bit = 0;
    int copy = n-1;
    while(copy>0){
        bit++;
        copy>>=1;
    }
    if(n == 1 && k == 0){cout<<"no\n"; return;}
    if(k == n){
        cout<<"Yes\n";
        for(int i = n-1; i>=0; i--){
            cout<<i<<' ';
        }
        cout<<nl;
        return;
    }
    //10
    ll look_at2 = k ^ n;
    if(1<<(bit) <= look_at2){
        cout<<"no\n";
        return;
    }else{
        //if k is 0 and n is a pow of 2 its bad?
        int look_at = (k^(n));
        //2
        vi pow_two;
        //1
        pow_two.pb(0);
        for(int i = 0; i<bit; i++){
            pow_two.pb(1<<i);
        } 
        vi arr;
        int ptr = 0; 
        for(int i =0 ; i<n; i++){
            if(ptr<pow_two.size() && pow_two[ptr] == i) {ptr++;}
            else arr.pb(i);
        }
        //5 ^ 1 = 4
        //1 0 0
        //
        for(int tz = 0; tz<bit; tz++){
            if(((look_at>>tz) & 1) == 0){
                //if there is not a 1
                arr.pb(pow_two[tz+1]);
            }
        }
        arr.pb(0);
        for(int tz = 0; tz<bit; tz++){
            if(((look_at>>tz) & 1) == 1){
                arr.pb(pow_two[tz+1]);
            }
        }
        cout<<"Yes\n"<<arr<<nl;
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
