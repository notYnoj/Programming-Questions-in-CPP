//actually this is a bad solution as it's n^2
class Solution {
public:
    vector<vector<int>> sieve; // Declare without initialization

    // Constructor to initialize the sieve
    Solution() : sieve(1001) {}

    void innit() {
        for(int i = 1; i <= 1000; i++) {
            for(int j = i; j <= 1000; j += i) {
                sieve[j].push_back(i);
            }
        }
    }

    int minSteps(int n) {
        innit();
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            // We can do minus one to get rid of the final factor
            for(int j = 0; j < sieve[i].size() - 1; j++) {
                int cur_factor = sieve[i][j];
                dp[i] = min(dp[i], dp[cur_factor] + (i / cur_factor));
            }
        }
        return dp[n];
    }
};

//a better greedy solution, which i initally wanted to do but backed away from it for some unknown reason
/*
int main(){
int n;
cin>>n;
int x = 0;
int f = 2;
while(n>1);
while(n%f == 0){
x+=f;
n/=f;
}
f++;
}
return x;
*/
