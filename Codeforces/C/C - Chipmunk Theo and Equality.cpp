#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#include <chrono>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(all(a));
        unordered_map<ll, ll> mp1;
        unordered_map<ll, ll> mp2;
        for(int i = 0; i<n;){
            int fact = 1;
            while(i+1 < n && a[i] == a[i+1]){
                fact++;
                i++;
            }
            int cur = a[i];
            int step = 0;
            while(cur != 1){
                mp1[cur] += fact * step; //to get here we do fact * stpe for all of em
                mp2[cur] += fact; //all facts can get here
                if(cur%2){
                    cur+=1;
                }else{
                    cur>>=1;
                }
                step++;
            }
            //we will be at step
            mp1[cur]+= fact * step;
            mp2[cur]+= fact;
            if(a[i] == 1){
                mp1[2] += fact * 1; //to get to 2 we just do one move
                mp2[2] += fact; //we can always get to 2
            }
            i++;
        }
        ll mnNum = LLONG_MAX;
        for(auto i: mp1){
            if(mp2[i.first] == n){
                mnNum = min(mnNum, i.second);
            }
        }
        cout<<mnNum<<'\n';
    }
}