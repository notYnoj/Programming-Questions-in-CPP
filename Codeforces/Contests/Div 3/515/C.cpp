//final time 20:48
#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll>>
using namespace std;
void solve(){
    string s;
    cin>>s;
    string n = s;
    s = "A"+n;
    int tnn = s.size();
    int l = 0;
    int r = tnn;
    int ans = r;
    //goal get to the n+1th cell (t+1)
  //binary searching answer, greeidly pick the most right of pos+mid
  //if we get to a positon where we get to tnn with a jump (aka we get to pos n+1) then were good!
  //otherwise searrch up
    while(l<=r){
        int mid = (l+r)/2;
        int pos = 0;
        bool tn = true;
        while((pos+mid)<tnn){
            bool tn1 = false;
            for(int i = (pos+mid); i>pos; i--){
                if(s[i] == 'R'){
                    pos = i;
                    tn1 = true;
                    break;
                }
            }
            if(!tn1) {
                tn = false;
                break;
            }
        }
        if(tn){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
