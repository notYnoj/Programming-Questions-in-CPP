#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mxN = 1e6+5;
ll dp[mxN][8];
int bitK(int n, int k){
    return (n>>k) & 1;
}
int main(){
    int N, M;
    cin>>N>>M;
    if(min(N, M)>=4){ // we have 4 odd numbers (4x4 is made up of 4 2x2) -> 2k+1*4 = 8k+4 = divsible by 2, not allowed
        cout<<-1;
    }
    else if(min(N,M) == 1){ //no squares are made
        cout<<0;
    }else{
        int a = 0;
        vector<vector<int>> grid(N, vector<int>(M)); //cin
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                char s;
                cin>>s;
                grid[i][j] = s-'0';
            }
        }
      //dp intial state
        for(int i = 0; i<mxN; i++){
            for(int j = 0; j<(1<<3); j++){
                dp[i][j] = 1e9;
            }
        }
      // set up a temp variable, a, for the base case.
        for(ll i = 0; i<N; i++) a += grid[i][0]*(1<<i);
        for(ll i = 0; i<(1<<N); i++){
        //find the needed changes __builtin_popcount couts the amount of 1s
          //thus we find the xor aka the amount needed to change
            dp[0][i] = __builtin_popcount(i^a);
        }
        for(ll col = 0; col<M-1; col++){// iaterate through all cols
            int col_mask = 0;
            for(ll temp = 0; temp<N; temp++) col_mask += grid[temp][col+1]*(1<<temp);
            for(int i = 0; i<(1<<3); i++){//itearte through current mask
                for(int j = 0; j<(1<<3); j++){//itearte through next mask
                    ll change = __builtin_popcount(col_mask^j); //change in next mask
                    ll possible = change + dp[col][i]; //change in next + current dp[col][mask] 
                    bool check = true;
                    for(int p = 0; p+1<N; p++){
                      //check if its legal
                        int c,d,e,f;
                        c = bitK(i, p);
                        d = bitK(j, p);
                        e = bitK(i, p+1);
                        f = bitK(j, p+1);
                        int sum = c+d+e+f;
                        if(sum % 2 == 0){
                            check = false;
                            break;
                        }
                    }
                    if(check){
                      //if legal then we can filter it.
                        dp[col+1][j] = min(possible, dp[col+1][j]);
                    }
                }
            }

        }
        ll ans = 1e9;
        //find ans, check [m-1] since thgat is the last one! (we are doing it by col so we need to find hte final col
        for(int i = 0; i<8; i++){
            ans = min(ans, dp[M-1][i]);
        }
        cout<<ans;


    }
}
