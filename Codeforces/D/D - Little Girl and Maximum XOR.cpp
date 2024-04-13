#include <bits/stdc++.h>
#define ll long long
using namespace std;
int countLeadingZeros(long long value) {
    // Convert the value to a bitset
    bitset<64> bits(value);

    // Count the number of leading zeros
    int count = 0;
    for (int i = 63; i >= 0; i--) {
        if (!bits[i]) {
            count++;
        } else {
            break;
        }
    }
    return count;
}
int main(){
    ll l, r;
    cin>>l>>r;
    ll a = l^r;
    if(!a){
        cout<<0;
    }else{
        int b = countLeadingZeros(a);
        int moves = 63 - b;
        cout<< 2*(1LL<<moves)-1;
    }

}
