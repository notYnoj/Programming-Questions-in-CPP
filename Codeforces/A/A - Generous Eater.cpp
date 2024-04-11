#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    int count = 2;
    while(n>0){
        count--;
        ans++;
        n--;
        if(count==0){
            count = 2;
            n--;
        }
    }
    cout<<ans;
}
