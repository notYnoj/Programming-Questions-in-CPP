//final time 48:03
#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pair<ll,ll>>
using namespace std;
const int mxN = 2e5+5;
int n;
int bads[mxN];
//bs and find the first one that makes it good! (aka bigger)
int bs(int num, int pos){
    int l = pos+1; //cant doubel count
    int r = n;
    int ans = n;
    while(l<=r){
        int mid = (l+r)/2;
        if((bads[mid]+num)>0){
            ans = mid;
            r= mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
    cin>>n;
    vector<int> students(n);
    vector<int> teachers(n);
    for(int i = 0; i<n; i++){
        cin>>teachers[i];
    }
    vpll sorted(n);
    for(int i = 0; i<n; i++){
        cin>>students[i];
      //find the difference that we need to overcome
        bads[i] = teachers[i] - students[i];
    }
    sort(bads, bads+n);
    ll ans = 0;

    for(int i = 0; i<n; i++){
        int zn = bs(bads[i], i);
        ans+= ((n)-zn);
    }
    cout<<ans;

}
