#include <bits/stdc++.h>
#define ll long long
#define vvi vector<vector<ll>> 
using namespace std;
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << (elem+1) << "\n";
    }
    return os;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string og = "LIT";
        if(count(s.begin(), s.end(), s[0]) == n){
            cout<<"-1\n";
            continue;
        }
        vector<int> ans;
        auto op = [&](int i){
            string z = og;
            z.erase(find(z.begin(), z.end(), s[i]));
            z.erase(find(z.begin(), z.end(), s[i + 1]));
            ans.push_back(i);
            s = s.substr(0, i+1) + z[0] + s.substr(i+1);
        };
        while(true){
            int a = count(s.begin(), s.end(), og[0]);
            int b = count(s.begin(), s.end(), og[1]);
            int c = count(s.begin(), s.end(), og[2]);
            if(a == b && b == c){break;}
            if(ans.size()>2*n){
                cerr<<"WRONG";
                return 1;
            }

            bool done = false;
            int poor = min(a,min(b,c));
            if(poor == a){
                for(int i = 0; i<s.size()-1; i++){
                    if(s[i] == s[i+1]){
                        continue;
                    }
                    if((s[i] == og[1] && s[i+1] == og[2])|| (s[i] == og[2] && s[i+1] == og[1])){
                        op(i);
                        done = true;
                        break;
                    }
                }
            }else if(poor ==b){
                for(int i = 0; i<s.size()-1; i++){
                    if(s[i] == s[i+1]){
                        continue;
                    }
                    if((s[i] == og[0] && s[i+1] == og[2])|| (s[i] == og[2] && s[i+1] == og[0])){
                        op(i);
                        done = true;
                        break;
                    }
                }
            }else{
                for(int i = 0; i<s.size()-1; i++){
                    if(s[i] == s[i+1]){
                        continue;
                    }
                    if((s[i] == og[1] && s[i+1] == og[0])|| (s[i] == og[0] && s[i+1] == og[1])){
                        op(i);
                        done = true;
                        break;
                    }
                }
            }
            if(done){
                continue;
            }else{
                //place the i
                //AA(PLACE HERE B THEN A [you get two places to put C])CBBB
                //BBBC(PLACE B HERE THEN A BEHIND)AA
                int rich = max(a, max(b,c));
                if(rich == a){
                    for(int i = 0; i<s.size()-1; i++){
                        if(s[i] == s[i+1]){
                            continue;
                        }
                        if(s[i] == og[0]){
                            op(i);//BBBACC
                            op(i+1);//BBBABCC
                            break;
                        }
                        else if(s[i+1] == og[0]){
                            op(i);//CCBABBB
                            op(i);
                            break;
                        }
                    }
                }
                else if(rich == b){
                    for(int i = 0; i<s.size()-1; i++){
                        if(s[i] == s[i+1]){
                            continue;
                        }
                        if(s[i] == og[1]){
                            op(i);//BBBACC
                            op(i+1);//BBBABCC
                            break;
                        }
                        else if(s[i+1] == og[1]){
                            op(i);//CCBABBB
                            op(i);
                            break;
                        }
                    }
                }else{
                    for(int i = 0; i<s.size()-1; i++){
                        if(s[i] == s[i+1]){
                            continue;
                        }
                        if(s[i] == og[2]){
                            op(i);//BBBACC
                            op(i+1);//BBBABCC
                            break;
                        }
                        else if(s[i+1] == og[2]){
                            op(i);//CCBABBB
                            op(i);
                            break;
                        }
                    }
                }

            }
        }
        cout<<ans.size()<<'\n';
        cout<<ans;

    }
}
