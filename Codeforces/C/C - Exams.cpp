#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
int n;
array<int, 2> a[5001];
int main() {
    //fastio
    fastio
    cin>>n;
    for(int i = 0; i<n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a, a+n);
    //for the first day take the minimum
    int amount = min(a[0][0], a[0][1]);
    for(int i = 1; i<n; i++){
        //if makes sense take
        if(a[i][1]>= amount){
            amount = a[i][1];
        }else{
            amount = a[i][0];
        }

    }
  //cout largest amount aka day when final exam is taken.
    cout<<amount;

}
