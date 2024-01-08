#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN = 1000;
int n, t;
//use array to keep track of original positions
ar<int, 2> a[mxN];
int main() {
    cin>>n>>t;
    if(n<4){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i = 0; i<n; i++){
        cin>>a[i][0];
        a[i][1] = i;
    }
    sort(a, a+n);
    for(int i = 0; i<n-3; i++){
        for(int j = i+1; j<n-2; j++){
            int l = j+1;
            int r = n-1;
            int target = t - a[i][0] - a[j][0];
            //two pointers
            while(l<r){
                int cur = a[l][0]+ a[r][0];
                if(target == cur){
                    cout<<a[i][1]+1<<" "<<a[j][1]+1<<" "<<a[l][1]+1<<" "<<a[r][1]+1;
                    return 0;
                }else if(cur<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
 
}
