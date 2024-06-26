#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) {

        int n, m;
        cin >> n >> m;
        int copy_m = m;
        vector<int> wins(n);
        vector<int> prep_time(n);

        int winss = 1;
        for (int i = 0; i < n; i++) {
            wins[i] = winss;
            int a;
            cin >> a;
            prep_time[i] = a;
            winss++;
        }
        int ans = -1;
        int r = n;
        int l = 1;
        vector<int> copy = prep_time;
        sort(prep_time.begin(), prep_time.end());
        int mx_BF_wins = 0;
        for (int i = 0; i < n; i++) {
            if (prep_time[i] > m) {
                break;
            } else {
                mx_BF_wins++;
                m -= prep_time[i];
            }
        }
        while (l <= r) {
            int mid = (l + r) / 2; //either get the position by defeating the dude at pos or defeating enough dudes
            // case 1
            if (mx_BF_wins>=wins[n-mid]){
                ans = mid;
                r = mid -1;
                continue;
            }
            //case2
            int cur = copy_m - copy[n-mid]; //need mid-1 wins
            if(cur>=0){
                int temp = 1;
                bool done = false;
                for(int i = 0; i<n; i++){
                    if(temp>=wins[n-mid]-1){
                        r = mid-1;
                        ans = mid;
                        break;
                    }
                    if(!done && prep_time[i] == copy[n-mid]){
                        done = true;
                        continue;
                    }
                    if(prep_time[i]>cur){
                        l = mid+1;
                        break;
                    }else{
                        cur-=prep_time[i];
                        temp++;
                    }
                }
            }else{
                l = mid+1;
            }
        }
        if (ans == -1) cout << n + 1 << '\n';
        else cout << ans << '\n';


    }
}
