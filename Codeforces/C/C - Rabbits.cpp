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
    int n;
    cin>>n;
    string s;
    //for each rabbit position
    cin>>s;
    int tz = 0;
    bool flag = (s[0] == '0');
    int i = 0;
    //there will always be some configuration/combination of L (left-facing) and R (right-facing) rabbits that can be placed within this sequence (0th )
    if(flag){
        bool skip = false;
        for(i; i<n; i++){
            if(s[i] == '1' && i<(n-1) && s[i+1] != '0'){
                break;
            }
        }
    }
    //if there is a continious statement then its good. otherwise it must be "even". continious statements include things that happen at the end
    flag = false;
    int size = 0;
    i++;
    for(i; i<n; i++){
        //im always going to currently start on a 1
        if(s[i] == '0' && s[i-1] == '0'){ //cont
            flag = true;
        }else if(s[i] == '0'){ // 10 ... (add 1 we don't know if its bad)
            //if its isolated check if the next 2nd one is good?
            size++;
        }
        else{
            if(i < n-1 && s[i+1] == '0'){
                continue; //this is fine
            }else{
                if(!flag && size % 2){
                    cout<<"No\n";
                    return;
                }
                //reset after this
                size = 0;
                flag = false;
            }
        }

    }

    cout<<"yes\n";
    



    //contingious blocks are good or ones that are 1 away and even in nature
    //cont or
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
