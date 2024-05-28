#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n, q;
ll calc(ll z) {
  //calm luh bs + math
  // here are the notes i took in the airport :D:
  /*
  Q = 4;
4+2+1
Z = 3


4+2
Z = 2;


(q-(z+1)*z-1) + gauss?


Q terms, only using the first z 

We know that the first one is complete.
Int a = q;
Z-1 terms now;


Sum of first z-1 terms of  (q-2, q-3…) 

Z-1 * 

    */
    ll a = q;
    a += (z-1) *(q-(z+1));
    a+=(z-1)*z/2;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    if(n == 1){
        cout<<0; //stupid case but this is why we read the problem
    }else {
        ll l = 1;
        ll r = q;
        ll myans = ULLONG_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (calc(mid) >= n) {
                myans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
      // cant use cout<<(myans == ULLONG_MAX?-1:myans) becasue it actually sets myans = -1 whihc ULLONG cant take lolz.
        if (myans == ULLONG_MAX) {
            cout << -1;
        } else {
            cout << myans;
        }

    }
}
