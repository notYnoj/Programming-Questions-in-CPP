#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
    
// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
void solve(){
    ll x, y, k;
    cin>>x>>y>>k;
    //x is the number of times we elimate pos y*1, y*2 ...
    //y is the multiple
    //k = position
    ll l = 0;
    ll r = (ll) 1e12+1; 
    ll ans = LLONG_MAX;
  //we have a line of numbers from 1-10^12, we want to find the number after x operations
  //1 operations consists of removing every number at index that has a multiple of y.
  //after this we want to find what number is at index k
  //to do this we can use binary search.
  //after every operation we remove (int) p/y (where p is the number of items we have left orignially 10^12)
  //now we want to find the min number where we have at least k items. this min number will be the number where we have exactly k items meaning that our answer will be this min number.
    //if we want to find index k we can find the minimum such that there are at least p elements left that will be our answer p
    while(l<=r){ //binary search
        ll mid = (l+r)/2; //middle number
        ll p = mid; //we need to subtract so create a new number
        //x operations
        for(int i = 0; i < x; i++){
            p -= (p/y);
        }
        if(p>=k){ //if there is at least p operations we set this to our min ans
            ans = min(ans, mid);
            r = mid-1; // we alr checked mid and it is good so set r 1 less
        }else{
            l = mid+1; //we checked mid and its bad so set l as mid+1
        }
    }
    if(ans == LLONG_MAX){
        cout<<"-1\n"; //no ans we set -1
    }else{
        cout<<ans<<endl; //there is an ans
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){solve();}
}d1
