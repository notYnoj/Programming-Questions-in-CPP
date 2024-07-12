#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct rectangle{
    ll x1,y1,x2,y2;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<rectangle> a(3);
    for(ll i = 0; i<3; i++){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        a[i].x1 = x1;
        a[i].y1 = y1;
        a[i].x2 = x2;
        a[i].y2 = y2;
    }
    auto get_intersect = [](rectangle x, rectangle y) ->rectangle{
        ll ax1 = x.x1, ay1 = x.y1, ax2 = x.x2, ay2 = x.y2;
        ll bx1 = y.x1, by1 = y.y1, bx2 = y.x2, by2 = y.y2;
        if(ax1>bx2 || bx1>ax2 || ay1>by2 || by1>ay2){
            rectangle ans;
            ans.x1 = -1000;
            ans.x2 = -1000;
            ans.y1 = -1000;
            ans.y2 = -1000;
            return ans;
        }
        rectangle ans;
        ans.x1 = max(ax1, bx1);
        ans.x2 = min(ax2, bx2);
        ans.y1 = max(ay1, by1);
        ans.y2 = min(ay2, by2);
        return ans;
    };
    auto get_area = [](rectangle x)->ll{
        return ((x.x2-x.x1)*(x.y2-x.y1));
    };
    ll total_area = get_area(a[0]);

    total_area-=get_area(get_intersect(a[1], a[0]));

    total_area-=get_area(get_intersect(a[2], a[0]));

    total_area += get_area(get_intersect(a[0],(get_intersect(a[1],a[2]))));

    cout<<(total_area<=0?"NO":"YES");
}
