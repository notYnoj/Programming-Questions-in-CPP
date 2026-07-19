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
    ll t, h, u;
    cin>>t>>h>>u;
    ll ans = 0;
    if(u>t){
        ans+= (4 * t);
        u-=t;
        t-=t;
    }else{
        ans+= (4 * u);
        t-=u;
        u-=u;
    }
    if(t == 0){

    }else{
        if(t>h){
            //per h we can have 2 ts and get 7
            ll multiple = min(h, t/2);
            ans+=(multiple*7);
            h-=multiple;
            t-=(multiple*2);
            if(t>0 && h > 0){
                t-=1;
                h-=1;
                ans+=5;

            }
        }else{
            ans+=(5*t);
            h-=t;
            t-=t;
        }
    }
    if(t>0){
        ans+=(2*t+1);
    }
    ans+=(h*3) + (u*3);
 
    cout<<ans<<nl; //bomboclatt this probelm was horrible
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
