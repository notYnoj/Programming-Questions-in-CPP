#include <bits/stdc++.h>
using namespace std;
int dfs(int b, vector<int> numbers){
    if(numbers.size() == 0){
        return 0;
    }
    if(b<0){
        return numbers.size();
    }

    vector<vector<int>> bit(2);
    for(auto i: numbers){
        if((i>>b)&1){
            bit[1].push_back(i);
        }else{
            bit[0].push_back(i);
        }
    }
    int temp = dfs(b-1, bit[1]) + min((int)1, (int)bit[0].size());
    int temp2 = dfs(b-1, bit[0]) + min((int)1, (int)bit[1].size());
    return max(temp, temp2);

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
//30 digits
//if you any with 0 in some bit and 1 in another bit
    int ans = dfs(30, a);
    cout<<n-ans;
}
