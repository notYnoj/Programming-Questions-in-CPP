#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>> stores(n);
        for(int i = 0; i<n; i++){
            int a, b;
            cin>>a>>b;
            stores[i] = {a,b};
        }
        multiset<int> usable;
        multiset<int> bigger;
        for(int i = 0; i<n; i++){
            bigger.insert(stores[i].second);
        }
        sort(stores.begin(), stores.end());
        int ans = INT_MAX;
        for(int i = 0; i<n-1; i++){
            auto cur = stores[i];
            bigger.erase(bigger.find(cur.second));
            auto possible = usable.lower_bound(cur.first);
            auto possible2 = usable.end();
            if(possible != usable.begin()) possible2 = prev(possible);
            if(possible2 != usable.end()){
                ans = min(ans, abs(cur.first - *(--bigger.end())));
                if(*(--bigger.end())<(possible!=usable.end()?*possible:INT_MIN)) ans = min(ans, abs(cur.first - *possible));
                if(*(--bigger.end())<(possible2!=usable.end()?*possible2:INT_MIN))ans = min(ans, abs(cur.first - *possible2));
            }else {
                int best = abs(cur.first - *possible);
                if (*(--bigger.end()) > *possible) ans = min(ans, abs(cur.first - *(--bigger.end())));
                else ans = min(ans, min(best, abs(cur.first - *(--bigger.end()))));
            }
            usable.insert(cur.second);
        }
        //last one
        auto nwords = usable.lower_bound(stores[n-1].first);
        auto nwords2 = (nwords!=usable.begin()?prev(nwords): usable.end());
        int t1 = (nwords != usable.end()? *nwords: -1000000001);
        int t2 = (nwords2 != usable.end()? *nwords2: -1000000001);
        int bestest = min(abs(stores[n-1].first - t1),abs(stores[n-1].first-t2));
        ans = min(ans, bestest);
        cout<<ans<<'\n';
    }
}
