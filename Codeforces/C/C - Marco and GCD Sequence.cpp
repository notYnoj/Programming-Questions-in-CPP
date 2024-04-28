#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i = 0; i<n; i++){
        cin>>s[i];
    }
    int x = s[0];
    for(int i = 1;i<n; i++){
        if(gcd(x, s[i]) != x){
            cout<<-1;
            return 0;
        }
    }
    cout<<2*n<<endl;
    for(int i = 0; i<n; i++){
        cout<<s[i]<<" "<<s[0]<<" ";
    }
}
