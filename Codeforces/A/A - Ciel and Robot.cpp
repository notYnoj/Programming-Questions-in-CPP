#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll x, y;
    cin>>x>>y;
    string s;
    cin>>s;

    //net change
    ll dx = 0;
    ll dy = 0;
    ll n = s.size();
    for(ll i = 0; i<n; i++){
        if(s[i] == 'U') dy++;
        else if(s[i] == 'D') dy--;
        else if(s[i] == 'R') dx++;
        else dx--;
    }
    int ca = 1;
    if(dx<=0 && dy>=0) ca = 2;
    else if(dx<=0 && dy<=0) ca =3 ;
    else if(dx>0 && dy<0) ca = 4;
    if(x == 0 && y == 0){
        cout<<"Yes";
    }else{
        ll l = 1;
        ll r = 10000000000000;
        bool check = false;
        while(l<=r){
            ll mid_point = (l+r)/2;
            ll mdx = mid_point*dx;
            ll mdy = mid_point*dy;
            ll xx = mdx;
            ll yy = mdy;
            if(mdx == x && mdy ==y) {
                check = true;
                break;
            }
            for(ll i = n-1; i>=0; i--){
                if(s[i] == 'U'){
                    yy--;
                }else if(s[i] == 'D'){
                    yy++;
                }else if(s[i] == 'R'){
                    xx--;
                }else{
                    xx++;
                }
                if(xx == x && yy ==y) {
                    check = true;
                    break;
                }

                mdx = min(mdx, xx);
                mdy = min(mdy, yy);

            }
            xx = mid_point*dx;
            yy = mid_point*dy;
            for(ll i = 0; i<n; i++){
                if(mid_point == 2){

                }
                if(s[i] == 'U'){
                    yy++;
                }else if(s[i] == 'D'){
                    yy--;
                }else if(s[i] == 'R'){
                    xx++;
                }else{
                    xx--;
                }
                if(xx == x && yy ==y) {
                    check = true;
                    break;
                }

            }
            if(ca == 1) {
                if (mdx+dx <= x && mdy+dy <= y) {
                    l = mid_point+1;
                } else {
                    r = mid_point - 1;
                }
            }else if(ca == 2){
                if(mdx-dx>=x && mdy-dy<= y){
                    l = mid_point+1;
                }else{
                    r = mid_point-1;
                }
            }else if(ca == 3){
                if(mdx-dx>=x && mdy-dy>= y){
                    l = mid_point+1;
                }else{
                    r = mid_point-1;
                }
            }else{
                if (mdx+dx <= x && mdy-dy>= y) {
                    l = mid_point+1;
                } else {
                    r = mid_point - 1;
                }
            }
        }
        if(!check) cout<<"No";
        else cout<<"Yes";
    }
}
