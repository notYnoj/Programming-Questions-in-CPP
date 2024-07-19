#include <bits/stdc++.h>
using namespace std;
bool check(const vector<vector<int>>& grid, int u, int p, vector<bool>& c){
    if(c[u]){
        return true;
    }
    c[u] = true;
    for(auto i: grid[u]){
        if(i == p){
            continue;
        }else{
            return check(grid, i, u, c);
        }

    }
    return false;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    vector<vector<int>> grid(n+1);
    vector<int> dsu(n+1);
    iota(dsu.begin(), dsu.end(), 0);
    if(n == 2) cout<<"1 1\n";
    else{
        //all disconnected can be grouped into 1
        // non disconnected must form own
        //all other ones can form own for their own sake
        auto find = [&](int a, const auto& self) -> int {
            if (dsu[a] == a) {
                return a;
            } else {
                return dsu[a] = self(dsu[a], self);
            }
        };

        auto merge = [&](int a, int b) {
            int x = find(a, find);
            int y = find(b, find);
            if(x<y){
                dsu[y] = x;
            }else{
                dsu[x] = y;
            }
        };
        for(int i =0; i<n; i++){
            merge(i+1,arr[i]);
            grid[i+1].push_back(arr[i]);
            grid[arr[i]].push_back(i+1);
        }
        vector<bool> found(n+1, false);
        int a = 0;
        int b = 0;
        int cd = 0;
        for(int i =0; i<n; i++){
            if(!found[find(i+1, find)]){
                found[find(i+1, find)] = true;
                vector<bool> c(n+1, false);
                if(check(grid, find(i+1, find), -1, c)){
                    a++;
                    b++;
                }else{
                    cd++;
                }
            }
        }
        if(cd){
            a++;
            b+=cd;
        }
        cout<<a<<' '<<b<<'\n';

    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
