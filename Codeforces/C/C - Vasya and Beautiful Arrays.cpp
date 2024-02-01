#include <bits/stdc++.h>
using namespace std;
int n, k, m, f, i;
const int mxN = 1e6+5;
int a[mxN];
int main() {
    cin>>n>>k;
    for(i =0; i<n; i++){
        cin>>a[i];
        if(i==0 || a[i]<m){
            m = a[i];
        }
    }
    //basically we go through the array until we find that f = 0 (initalized again)
    //then we do the mod operator if its not good aka %m>k (more than decreasable till we get a factor) we have to shrink m by 1 and we have to make f postive
    //if found it stops executing
    do {
        for (f=i=0; i < n; i++) {
            while (a[i] % m > k) {
                f = m--;
            }
        }
    }while (f);
    cout << m;
}
