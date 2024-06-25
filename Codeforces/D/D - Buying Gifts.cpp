#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> first(n);
        vector<int> second(n);
        for(int i = 0; i<n; i++){
            cin>>first[i];
        }
        for(int i = 0; i<n; i++){
            cin>>second[i];
        }
        vector<int> copy = second;
        sort(copy.begin(), copy.end());
        int ans = INT_MAX;
        for(int i = 1; i<n; i++){
            ans = min(ans, abs(first[0]-second[i]));
        }
        if(ans == 0){
            cout<<0<<'\n';
        }else{
            //bs
            for(int i = 1; i<n; i++){
                int cur = first[i];
                auto it = lower_bound(copy.begin(), copy.end(), cur);
                auto it2 = copy.end();
                if(it != copy.begin()) it2 = prev(it);
                if(it2 == copy.end()){
                    if(*it != second[i]) ans = min(ans, abs(cur - *it));
                    else if() ans = min(ans, abs(cur - *next(it)));
                }else{

                }
            }
            cout << ans << '\n';
        }
    }
}
