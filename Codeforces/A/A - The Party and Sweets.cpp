#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;//n boys m girls
    cin>>n>>m;
    vector<ll> min_boys(n);
    vector<ll> max_girls(m);
    ll a = LLONG_MIN;
    ll b = LLONG_MAX;
    for(ll i =0; i<n; i++){
        cin>>min_boys[i];
        a = max(a, min_boys[i]);
    }
    for(ll i =0; i<m; i++){
        cin>>max_girls[i];
        b = min(b, max_girls[i]);
    }
    if(a>b){
        cout<<-1;
    }else{
      //simple greedy question
        sort(min_boys.begin(), min_boys.end());
        sort(max_girls.begin(), max_girls.end()); 
        ll ans = 0;
      //sort the things out
      //then we want if n-1 is equal to the min girls then we know that the ifnal dude can give everyoene waht they want and rest can give min
        if(min_boys[n-1] == max_girls[0]){
            ans = accumulate(max_girls.begin(), max_girls.end(), 0LL);
            for(ll i = 0; i<n-1; i++) ans+=(min_boys[i]*m);
        }else{
          //otherwise the n-1 dude cna give all the girls what htey want but 1
            ans = accumulate(max_girls.begin(), max_girls.end(), 0LL);
            ans+= min_boys[n-1]; 
          //n-2 gives then what the final girl wants and then gives the other ones the cheapest
            ans+= (min_boys[n-2]*(m-1));
            for(ll i = 0; i<n-2; i++){
              //all other boys are broke boys lol jkjk but in terms of problem yeah kinda!
                ans+=(min_boys[i]*m);
            }
        }
        cout<<ans;
    }
}
