#include <bits/stdc++.h>
using namespace std;
//4*n queries
int main(){

    //go thru each point wth length n-1?, station urself at the next point
    int n;
    cin>>n;
    string top = "", bottom = "";
    int r = 1, c =1;
    for(int i = 0; i<n-1; i++){
        cout<<"? "<< r+1<<" "<<c<<" "<<n<<" "<<n<<endl;
        string s;
        cin>>s;
        if(s == "YES"){
            top+="D";
            r++;
        }else{
            top+="R";
            c++;
        }
    }
    r = n;
    c= n;
    for(int i = 0; i<n-1; i++){
        cout<<"? "<< 1<<" "<<1<<" "<<r<<" "<<c-1<<endl;
        string s;
        cin>>s;
        if(s == "YES"){
            bottom+="R";
            c--;
        }else{
            bottom+="D";
            r--;
        }
    }
    reverse(bottom.begin(), bottom.end());
    cout<<"! "<<top<<bottom;
}
