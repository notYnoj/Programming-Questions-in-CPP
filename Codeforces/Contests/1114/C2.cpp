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
    string a,b;
    cin>>a>>b;
    //like consider if we can make it first
    //if we can then working form right to left of the string b could be optimal
    //at every index there is one check do we have one to the direct right?
    //if we do we can 
    //0011 -> 0011
    //we can do this with stacks
    array<int, 2> az{};
    array<int, 2> bz{};
    vi stkEA, stkOA;
    vi stkEB, stkOB;
    for(int i = 0; i<n; i++){
        if(i%2){
            if(a[i] == '1'){
                az[0]++;
                stkOA.pb(i);
            }
            if(b[i] == '1'){
                bz[0]++;
                stkOB.pb(i);
            }
        }else{
            if(a[i] == '1'){
                az[1]++;
                stkEA.pb(i);
            }
            if(b[i] == '1'){
                bz[1]++;
                stkEB.pb(i);
            }
        }
    }
    if(az[0] == bz[0] && az[1] == bz[1]){
        ll ans = 0;
        while(!stkOA.empty()){
            //closelst gets there first
            ans += (llabs(stkOA.back() - stkOB.back()));
            stkOA.pop_back(); 
            stkOB.pop_back();
        }
        while(!stkEA.empty()){
            ans += (llabs(stkEA.back() - stkEB.back()));
            stkEA.pop_back(); 
            stkEB.pop_back();
        }
        //we move 2 per move so we can divide by 2 and everything is good
        cout<<ans/2<<nl;  
        return;
    }else{
        cout<<-1<<nl;
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