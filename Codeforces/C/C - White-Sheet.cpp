#include <bits/stdc++.h>
using namespace std;
struct rectangle{
    int x1,y1,x2,y2;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<rectangle> a(3);
    for(int i = 0; i<3; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        a[i].x1 = x1;
        a[i].y1 = y1;
        a[i].x2 = x2;
        a[i].y2 = y2;
    }
    auto get_intersect = [](rectangle x, rectangle y) ->rectangle{
        if()
    };
    auto get_area = [](rectangle x)->int{
        return ((x.x2-x.x1)*(x.y2-x.y1));
    };
    int total_area = get_area(a[0]);
    total_area-=get_area(get_intersect(a[1], a[0]));
    total_area-=get_area(get_intersect(a[2], a[0]));
    total_area += get_area(get_intersect(a[0],(get_intersect(a[1],a[2]))));

    cout<<(total_area<=0?"NO":"YES");
}
