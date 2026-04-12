#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
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
    vector<ll> a(n);
    cin>>a;
    //Think about this:
    /* Each number has a contribution when a part of a subsegmenet ai
    Lets call a number a root if a subsegement ai can be compressed to solely that number
    That is if we have a subsegement with ai, ai+1, ai+2 ...
    This entire subsegement can be compressed to only ai using our operator
    When looking at another superset subsegement that contains ai and specfically this critcal value, ai's entire contribution is 1
    Each unique subsegement is simply defined by a unique start and end pair (i,j)
    A number can be compressed only if ai-1 is found within this set
    If ai-1 is not found there will be an additional contirbution since ai cannot be compressed
    So from the pos of ai-1 -> i ->; n there will be an extra contribution from i
    to "contain" i, any number from the left and any number from the right should be chosen
    So the number of unique subsegments where i contributes is (i-ai) * (n-i)
    2 3 4 4 5 3,  n = 6  i = 2
    1 3 5 7 9
    1 * 5 + 2 * 4 + 3*3 + 4*2 + 5*1 = 35
    */
  //bascially 
   stack<pair<ll,ll>> stk;
   vector<ll> critVal(n, -1);
   //6
   for(ll i = 0; i < n ; i++){
    //the first time we see its parent we add it, so like if we see it then we pop it
    while(!stk.empty() && (stk.top().first > a[i] - 1)){
        stk.pop();
    }
    if(!stk.empty() && stk.top().first == a[i] -1){
        pii a = stk.top();
        critVal[i] = a.second;
    }else{
        stk = {};
    }
    stk.push({a[i], i});
   }
   ll ans = 0;
   for(ll i = 0; i<n; i++){
        ans += (i- critVal[i]) * (n - i);
   }
   cout<<ans<<endl;
}

int main(){
    cin>>t;
    while(t--){
        solve();
    }
}
