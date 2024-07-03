#include <bits/stdc++.h>
const int mxN = 1e5+5;
using namespace std;
vector<vector<int>> sieve(mxN);
void init_sieve(){
    for(int i =2; i<mxN; i++){
        for(int j = i; j<mxN; j+=i){
            sieve[j].push_back(i);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    }
    if(m == 1){
        cout<<0<<"\n";
        return;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n-1, looking = (m/2)+1;
    while(l<r && a[l]<looking) l++;
    r = l;
    int ans = INT_MAX;
    set<int> st;
    vector<int> sizes(m+1);
    queue<vector<int>> q;
    while(r<n){
        auto& z = sieve[a[r]];
        vector<int> hold;
        for(int&i: z){
            if(i>m){
                break;
            }
            st.insert(i);
            sizes[i]++;
            hold.push_back(i);
        }
        q.push(hold);
        while(st.size() == (m-1)){
            ans = min(ans, a[r]-a[l]);
            for(int& i: q.front()){
                sizes[i]--;
                if(sizes[i] == 0) st.erase(i);
            }
            q.pop();
            l++;
        }
        r++;
    }
    cout<<(ans!=INT_MAX?ans:-1)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    init_sieve();
    while(t--){
        solve();
    }
}
