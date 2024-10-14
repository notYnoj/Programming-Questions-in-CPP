#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}

int main(){
    int t;
    cin>>t;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(t--) {
        auto ask = [&](string s)->bool{
            cout<<"? "<<s<<endl;
            bool tz;
            cin>>tz;
            return tz;
        };
        int n;
        cin >> n;
        string front = "0";
        bool can = ask(front);
        if(!can){
            string result(n, '1');
            cout<<"! "<<result<<endl;
            continue;
        }
        for (int i = 0; i < n-1; i++) {
            front+='0';
            if(!ask(front)){
                front.pop_back();
                front+='1';
                if(!ask(front)){
                    front.pop_back();
                    break;
                }
            }
        }
        //TC:
        // 0000
        // 0101
        // 001010000111
        // 11010010
        int a = n-front.size();
        for(int i = 0; i<a; i++){
            string nw = "0"+front;
            if(!ask(nw)){
                front = "1"+front;
            }else{
                front = nw;
            }
        }
        
        cout<<"! "<<front<<endl;

    }


}
