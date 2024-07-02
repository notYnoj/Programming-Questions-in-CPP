#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;
    while(q--){
        char c;
        int k;
        cin>>k>>c;
        if(k == n){
            cout<<n<<'\n';
            continue;
        }
        int l = 0;
        int r = k-1;
        int count = 0;
        int ans = k;
        for(int i = 0; i<=r; i++){
            if(s[i] == c){
                count++;
            }
        }
        while(count-- && r<n){
            r++;
            if(s[r] == c){
                count++;
            }
            ans++;
        }
        while(r+1<n && s[r+1] == c){
            ans++;
            r++;
        }
        if(r == n){
            cout<<n<<'\n';
            continue;
        }
        if(ans == n){
            cout<<n<<'\n';
            continue;
        }
        while(r<n){
            if(s[l] == c){
                while(s[l] == c){
                    l++;
                }
            }
            l++;
            r++;
            assert(s[r]!=c);
            while(r+1<n && s[r+1] == c){
                r++;
            }
            ans = max(ans, (r-l+1));
        }
        cout<<ans<<"\n";
    }
}
