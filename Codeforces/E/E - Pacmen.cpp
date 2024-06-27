#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> packmen, food;
    for(int i =0; i<n; i++){
        if(s[i] == 'P') packmen.push_back(i);
        if(s[i] == '*') food.push_back(i);
    }
    int l = 0;
    int r = 2*n;
    int ans = 0;//suboptimal to go 1 pm go half left and all right 1.5x basically 2n
    while(l<=r){
        int mid = (l+r)/2;
        int cur = 0;
        for (int x : packmen) {
            int from = x, to = x;
            while (cur < (int) food.size()) {
                from = min(from, food[cur]);
                to = max(to, food[cur]);
                int need = to - from + min(to - x, x - from); //optimally pick either go right first and hten left or go left first thenr ight (whcihever is least)
              //then its js the distance from the current one (most left -> most right) then u also add the distance u traveled to get there again
                if (need > mid) {
                    break;
                }
                cur++;
            }
        }
        if(cur == food.size()){
            r = mid-1;
            ans = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<ans;
}
