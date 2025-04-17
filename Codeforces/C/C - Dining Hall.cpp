#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int mxN = 250;
vector<pii> best1;
vector<pii> best2;
vector<pii> moves = {{1,1}, {1,2}, {2,1}, {2,2}};
void precomp(){
    for(int i = 0; i<mxN; i++){
        for(int j = 0; j<mxN; j++){
            for(auto z:moves){
                best1.push_back({3*i+z.first, 3*j+z.second});
            }
        }
    }
    for(int i = 0; i<316; i++){
        for(int split = 0; split<=i; split++){
            best2.push_back({split, i-split});
        }
    }
    auto cmp = [&](pii a, pii b){
        int d1 = a.first+a.second + ((a.first%3 == 2) && (a.second%3 ==2) ? 2 : 0);
        int d2 = b.first+b.second + ((b.first%3 == 2) && (b.second%3 ==2) ? 2 : 0);
        if(d1!=d2){
            return d1<d2;
        }else{
            if(a.first!=b.first){
                return a.first<b.first;
            }else{
                return a.second<b.second;
            }
        }

    };
    sort(best1.begin(), best1.end(), cmp);
}

void solve(){
    //table i,j

    int n;
    cin>>n;
    set<pii> used; //(x,y) = x*250+y
    //suppose for any 0 we are trying to find where he is going in our array
    vector<int> arr(n);
    int t1 = 0;
    int t2 = 0;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<pii> ans;
    for(auto i: arr){
        if(i){
            while(true){
                auto posb = best1[t1++]; //actual pos it could go to
                if(used.find(posb) == used.end()){
                    ans.push_back(posb);
                    used.insert(posb);
                    break;
                }
            }
        }else{
            while(true) {
                auto posb = best2[t2++]; //actual pos it could go to
                pii posb2 = {3*posb.first+1, 3*posb.second+1};
                posb = posb2;
                if (used.find(posb) == used.end()) {
                    ans.push_back(posb);
                    used.insert(posb);
                    break;
                }
            }
        }

    }
    for(auto i: ans){
        cout<<i.first<<' '<<i.second<<"\n";
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomp();
    int q;
    cin>>q;
    while(q--){
        solve();
    }

}
