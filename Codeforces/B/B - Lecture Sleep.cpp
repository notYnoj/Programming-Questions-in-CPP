#include <bits/stdc++.h>
using namespace std;
//sldiing window lolz
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> lectures(n);
    for(int i =0 ;i<n; i++){
        cin>>lectures[i];
    }
    vector<int> sleep(n);
    int sum = 0;
    for(int i = 0; i<n; i++){
        cin>>sleep[i];
        if(sleep[i]){
            sum+=lectures[i];
        }
    }
    int ans = sum;
    int t = 0;
    int l = 0;
    int r = k-1;
    for(int i = l; i<=r; i++){
        if(!sleep[i]){
            t+=lectures[i];
        }
    }
    while(r<n){
        ans = max(ans, sum+t);
        if(!sleep[l]) t-=lectures[l];
        l++;
        r++;
        if(!sleep[r])t+=lectures[r];
    }
    cout<<ans;
}
