#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;
    
// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}

void solve(){
    int n,k;
    cin>>n>>k;
    //find a xor factorization of n wit k numbers that maximizes. wehre for each number can only be max of n
    //max is n*k
    if(k%2 == 1){
        for(int i = 0; i<k; i++){
            cout<<n<<' ';
        }
        cout<<'\n';
    }else{
        //So what we need to notice here is how we are going to make max sum
        //normally analyzing its 1 by 1 (since they don't affect each other really) is good for bitwise operator questions
        //So, we can notice that in our final series to have n -> if bit is turned on in n, we need to have that bit an odd amount of times
        //within k numbers since we have even here only we have to add in all but 1. 
        //if it is turned off we have it an even amount of times. Where can we add this? In numbers that are less than n. So we can't add this to the numbers
        //where we have been adding odd bits. That is the intution behind this question
        vector<int> a(k, 0);
        int bad = 0; //currently everything is "good" where we can add the 1s but not the 0s 1s once we start getting bits this will increase by 1 each time
        
        for(int i = 30; i>=0; i--){
            if((n>>i) & 1){
                for(int j = 0; j<k; j++){
                    //add to everything but 1 (we cna just do bad_pos cuz then we can add more stuff later on downt here)
                    if(j == min(k-1, bad)) continue;
                    a[j] += 1<<i;
                }

                if(bad<k) bad++; // if less than ts we can have more than 1 bad pos but we don't want to make it over

            }else{
                for(int j = 0; j< (bad%2?bad-1:bad); j++){
                    a[j] += 1<<i;
                }
            }

        }
        cout<<a<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
