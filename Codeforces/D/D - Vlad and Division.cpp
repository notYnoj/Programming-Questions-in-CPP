//time taken overall 37:26, though PCBC interruptions probably inflated these numbers lol
/*#include <bits/stdc++.h>
using namespace std;
int cases;
const int m = pow(2,31);
void solve(){
    int n; cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        int t;
        cin>>t;
        a[i] = t;
    }
    vector<vector<int>> ans;
    for(int i = 0 ;i<n; i++){
        bool placed = false;
        for(int j = 0; j<ans.size(); j++){
            if(!(m^(a[i] ^ ans[j][0])) && ans[j].size()<2){
                placed = true;
                ans[j].push_back(a[i]);
                break;
            }
        
        }
        if(!placed){
            ans.push_back({a[i]});
        }
    }
    cout<<ans.size()<<"\n";
}
int main(){
    cin>>cases;
    while(cases--){
        solve();
    }
} */
//TLE o(N^2), by xor twice with 2^31 we are esseintally saying what bits are different in a[i] and ans[j][0], and looping thru all numbers again wc so sad :((((
//o(N) idea: start with N since xor is culmiative we only have to do it once then we can use hashmaps
#include <bits/stdc++.h>
using namespace std;
int cases;
const int mxN = pow(2,31);
void solve(){
    int n; cin>>n;
    map<unsigned int, unsigned int> hsh;
    int ans = n;
    for(int i = 0; i<n; i++){
        int t;
        cin>>t;
        int needed = mxN^t;
        if(hsh.find(needed)!=hsh.end() && hsh[needed]>0){
            ans--;
          //we used needed
            hsh[needed]--;
        }else{
          //we place that we have a waiting t
            hsh[t]++;
        }
    }

    cout<<ans<<"\n";
}
int main(){
    cin>>cases;
    while(cases--){
        solve();
    }
}
