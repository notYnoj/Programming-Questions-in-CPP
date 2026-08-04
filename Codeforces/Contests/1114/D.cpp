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
    vi a(n);
    cin>>a;
    vi copyA = a;
    sort(all(a));
    if(a[0] != 0){
        cout<<-1<<nl;
        return;
    }
    vector<pll> unique;
    for(int i = 0; i<n; i++){
        if(unique.empty()){
            unique.pb({a[i], 1});
        }else{
            if(unique.back().first == a[i]){
                unique.back().second+=1;
            }else{
                unique.pb({a[i], 1});
            }
        }
    }
    int k = unique.size();
    vi ret(k);
    for(int i = 0; i<k-1; i++){
        ll diff = unique[i+1].first - unique[i].first;
        //gotta get an even split 
        if(diff % unique[i].second != 0){
            cout<<-1<<nl;
            return;
        }
        ret[i] = diff/unique[i].second;
        if( i > 0 && ret[i] <= ret[i-1]){
            cout<<-1<<nl;
            return;
            //has to come out increasing otherwise shadows would be added elsewehre
        }
    }
    ret[k-1] = (k==1) ? 1 : (ret[k-2] + 1); //we only need the smallest one at the end this should be fine
    vi vals(k);
    //is sorted
    for(int i=0; i<k; i++) vals[i] = unique[i].first;
    vi ans(n);
    //find which one we need from ret
    for(int i = 0; i<n; i++){
        ans[i] = ret[lower_bound(all(vals), copyA[i]) - vals.begin()];
    }
    cout<<ans<<nl;
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