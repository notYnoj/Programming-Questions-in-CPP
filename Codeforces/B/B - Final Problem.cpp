#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> team(n);
    for(int i = 0 ;i<n; i++){
        cin>>team[i];
    }
    sort(team.begin(), team.end());
    vector<bool> has(n, false);
    vector<int> ans(10);
    for(int i = 0; i<10; i++){
        cin>>ans[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<10; j++){
            if(team[i]>=ans[j]){
                has[i] = true;
                break;
            }
        }
    }
    bool ok = true;
    for(int i = 0; i<n; i++){
        if(!has[i]){
            cout<<team[i];
            ok = false;
            break;
        }
    }
    if(ok) cout<<10;
}
