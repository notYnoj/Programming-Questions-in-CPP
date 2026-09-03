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
    int n;
    cin>>n;
    vi a(n); //height changes // 0 is stays height 1 = goes up
    cin>>a;
    vector<pii> ranges;
    for(int i = 0; i<n; i++){
        int l,r;
        cin>>l>>r;
        ranges.pb({l,r});
    }
    int h = 0;
    int reserves = 0;
    vi reserves2;
    //consider if at any point we must take from reservers. we can do this if resreves has stuff in it. just take it and then pop back set it equal ot 1 then we are good
    //if reserves and reserve2.size() ! agree pop back
    for(int i = 0; i<n; i++){
        if(a[i] != -1){
            h+=a[i];
            if(h>ranges[i].second){
                cout<<"-1\n";
                return;
            }else if(h>=ranges[i].first && h <= ranges[i].second){
                reserves = min(reserves, ranges[i].second - h);
            }else{
                if(h+reserves>=ranges[i].first){
                    while(h < ranges[i].first){
                        reserves--;
                        int turn_on = reserves2.back();
                        a[turn_on] = 1;
                        reserves2.pop_back();
                        h++;
                    }
                    reserves = min(reserves, ranges[i].second - h);
                }else{
                    cout<<"-1\n";
                    return;
                }
            }
        }else{
            reserves++;
            reserves2.pb(i);
            if(h>ranges[i].second){
                cout<<-1<<nl;
                return;
            }
            else if(h < ranges[i].first){
                if(h + reserves>=ranges[i].first){
                    while(h < ranges[i].first){
                        reserves--;
                        int turn_on = reserves2.back();
                        a[turn_on] = 1;
                        reserves2.pop_back();
                        h++;
                    }
                    reserves = min(reserves, ranges[i].second - h);
                }else{
                    cout<<-1<<nl; 
                    return;
                }
            }else{
                reserves = min(reserves, ranges[i].second - h);
            }
        }
        if(reserves != reserves2.size()){
            cerr<<i<<nl;
            assert(reserves < reserves2.size());
            while(reserves2.size() != reserves){
                reserves2.pop_back();
            }
        }
    }
    for(int i = 0; i<n; i++) if(a[i] == -1) a[i] = 0;
    cout<<a<<nl;
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
