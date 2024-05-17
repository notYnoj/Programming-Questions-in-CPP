#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> fonts(n);
    for(int i =0; i<n; i++){
        cin>>fonts[i];
    }
    vector<int> costs(n);
    for(int i = 0 ; i<n; i++){
        cin>>costs[i];
    }
    int ans = INT_MAX;
    for(int j = 1; j<n-1; j++){
        int a = INT_MAX;
        int b = INT_MAX;
        for(int i = 0; i<n; i++){
            if(i == j){
                continue;
            }
            if(i<j){
                if(fonts[i]<fonts[j]){
                    a = min(a, costs[i]);
                }
            }else{
                if(fonts[i]>fonts[j]){
                    b = min(b, costs[i]);
                }
            }
        }
        if(a!=INT_MAX && b!=INT_MAX) {
            ans = min(ans, (a + b + costs[j]));
        }
    }
    cout<<(ans == INT_MAX?-1:ans);

}
