#include <bits/stdc++.h>
using namespace std;
int m;
string s;
vector<int> dfs(int pos, vector<int> ans, int l, int r){
    if(pos == m){
        return ans;
    }
    for(int i = 0; i<10; i++){
        if(s[i] == '1'){
            if(ans.back() != i+1){
                if(pos%2){
                    int nwr = r+i+1;
                    if(nwr>l){
                        ans.push_back(i+1);
                        vector<int> main = dfs(pos+1, ans, l, nwr);
                        if(!main.empty()){
                            return main;
                        }
                        ans.pop_back();
                    }
                }else{
                    int nwl = l+(i+1);
                    if(nwl>r){
                        ans.push_back(i+1);
                        vector<int> main = dfs(pos+1, ans, nwl, r);
                        if(!main.empty()){
                            return main;
                        }
                        ans.pop_back();
                    }
                }
            }
        }
    }

    return {};
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    cin>>m;
    vector<int> main;
    for(int i = 0; i<10; i++){
        if(s[i] == '1'){
            vector<int> ans = dfs(1, {i+1}, i+1, 0);
            if(!ans.empty()){
                main = ans;
                break;
            }
        }
    }
    if(main.empty()){
        cout<<"NO";
    }else{
        cout<<"YES\n";
        for(int i: main){
            cout<<i<<" ";
        }
    }
}
