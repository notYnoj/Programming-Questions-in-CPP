//my own mono stack sol:
#include <bits/stdc++.h>
using namespace std;
int t;
void solve(){
    int n;
    cin>>n;

    vector<long long> a(n);

    for(int i = 0; i<n; i++) cin>>a[i];

    if(n == 1){
        cout<<0<<endl;
        return;
    }
    vector<pair<long long, long long>> s;
    s.push_back({0, 1});
    for(long long i = 1, cur_sum = a[0], counter = 1; i<=n; i++){
        if(i == n){
            if(cur_sum != 0 && counter != 0){
                pair<long long, long long> tp = {cur_sum, counter};

                while(!s.empty() && tp.first/tp.second<=s.back().first/s.back().second){

                    tp.first+=s.back().first;
                    tp.second+=s.back().second;
                    s.pop_back();
                }
                s.push_back(tp);
            }
            break;
        }
        long long cur = a[i];
        if(cur>(cur_sum/max(1LL, counter))){
            long long cur_average = cur_sum/max(1LL,counter);
            auto tp = s.back();
            if(tp.first/tp.second<cur_average){
                s.push_back({cur_sum, counter});
                cur_sum = a[i];
                counter = 1;
                continue;
            }
            tp.first+=cur_sum;
            tp.second+=max(1LL,counter);
            s.pop_back();
            while(!s.empty() && tp.first/tp.second<=s.back().first/s.back().second){
                tp.first+=s.back().first;
                tp.second+=s.back().second;
                s.pop_back();
            }
            s.push_back(tp);
            cur_sum = a[i];
            counter = 1;
        }else{
            cur_sum+=a[i];
            counter++;
        }

    }
    cout<<((s.back().first/s.back().second)+(s.back().first%s.back().second?1:0) - (s[1].first/s[1].second))<<endl;
}
int main(){
    cin>>t;
    while(t--) solve();
}




/*Junhui's Prefix + Suffix Sum Solution:
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<long long> prefix(n);
    vector<long long> suffix(n);
    prefix[0] = a[0];
    suffix[n-1] = a[n-1];
    for(long long i = 1; i<n; i++){
        prefix[i] = prefix[i-1]+a[i];
    }
    for(long long i = n-2; i>=0; i--){
        suffix[i] = suffix[i+1]+a[i];
    }

    for(long long i = 0; i<n; i++){
        prefix[i]/=(i+1);
    }
    long long counter = 1;
    for(long long i = n-1; i>=0; i--){
        if(suffix[i]%counter){
            suffix[i]/=counter;
            suffix[i]++;
        }else suffix[i]/=counter;
        counter++;
    }
    cout<<*max_element(suffix.begin(), suffix.end()) - *min_element(prefix.begin(), prefix.end())<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}

explanation:
The prefix esseintally has the smallest posisble range of going up. So esseintally whichever one is the worst. There is a point where the averages of these things is bad and cannot be moved more.
The suffix esseintally has the biggest possible range of the things going down. So when we average stuff out as is optimal it cannot be any more down average. then we js take the subtract of these
*/
