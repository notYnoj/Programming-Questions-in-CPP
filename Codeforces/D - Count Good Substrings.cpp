#include <bits/stdc++.h>
using namespace std;
long long cnt[2][2];
string s;
//if compressed it will always alternate, now we can use this, if the parity is equal it will be odd, else even, use this!
int main(){
    cin>>s;
    long long odd = 0;
    long long even = 0;
    int cur = 0, next;
    for(int i = 0; i<s.size(); i++){
        next = (cur+1)%2;
        odd+= cnt[s[i]-'0'][cur];
        even+= cnt[s[i]-'0'][next];
        odd++;
        cnt[s[i]-'0'][cur]++;
        cur = next;
 
    }
    cout<<even<<" "<<odd;
}
