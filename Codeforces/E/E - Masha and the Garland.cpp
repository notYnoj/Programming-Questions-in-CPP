#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    //consider consequtive sequences where they are "off" aka they aren't either 10101 or 01010
    //whta does this look like
    //let like . denote correct and x denote wrong
    //. xxx . xxx .. 
    //now consider what happens when we look at the opposite good stirng
    //this turns into x ... x ... xx
    //so for splits of n we need at most floor(n/2) since there will be n/2+1 good and n/2 bad 
    //so if k>=floor(n/2) we can do it
    //how do we find n tho
    //when there is consecutive there makes a new group so just count amount of consecutive sequences (either good -> bad or bad->good)
    vector<int> pref(n, 0);
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + (s[i] == s[i-1]);
    }
    for(int i = 0; i<q ;i++){
        int l,r,k;
        cin>>l>>r>>k;
        l--;
        r--;
        int needed = (pref[r] - pref[l] + 1)/2;
        //if eeach one makes a gap then there gaps + 1 = total then total/2 (int divison is good)
        if(needed<=k){
            cout<<"Yes\n";
        }else{cout<<"no\n";}
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
