#include <bits/stdc++.h>
using namespace std;
long long gauss(long long n){
    return (long long)((long long)(n+1)*n/2);
}
int main(){
    string s;
    int n, m;
    cin>>n>>m;
    cin>>s;
    vector<char> ok(m);
    for(int i = 0; i<m; i++){
        cin>>ok[i];
    }
    vector<bool> bad(26, true);
    for(char i: ok){
        bad[i-'a'] = false;
    }
    long long ans = 0;
    int last = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if(bad[s[i]-'a']){
            ans+=gauss(i-j);
            while(i<n && bad[s[i]-'a']){
                i++;
            }
            j = i;
            last = j;
        }
    }
    if(last != n-1 || !bad[s[last]-'a']){
        ans+=gauss(n-last);
    }
    cout<<ans;

}
