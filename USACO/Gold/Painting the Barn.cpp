#include <bits/stdc++.h>
using namespace std;
const int WIDTH = 201;
int main(){
    vector<vector<int>> pref(WIDTH, vector<int>(WIDTH));
    int n,k;
    cin>>n>>k;
    for(int i =0; i<n; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int h = x1; h<=x2; h++){
            pref[h][y1]++;
            if(y2+1 <=200){
                pref[h][y2+1]--;
            }
        }
    }
    int ans1 = 0;
    for(int i =0; i<WIDTH; i++){
        int cur = 0;
        for(int j = 0; j<WIDTH; j++){
            cur+=pref[i][j];
            pref[i][j] = cur;
            if(pref[i][j] == k) ans1++;
        }
    }
    vector<vector<int>> a(WIDTH, vector<int>(WIDTH));
    for(int i = 0; i<WIDTH; i++){
        a[i][0] = (pref[i][0]+1 == k?1:(pref[i][0] == k?-1:0));
        a[0][i] = (pref[0][i]+1 == k?1:(pref[i][0] == k?-1:0));
    }
    for(int i =1; i<WIDTH; i++){
        for(int j = 1; j<WIDTH; j++){
            a[i][j] = (pref[i][j]+1 == k?1:(pref[i][j] == k?-1:0));
            a[i][j] += (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
        }
    }
    for(int i = 0; i<WIDTH; i++){
        for(int j = 0; j<WIDTH; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }

    auto getRec= [=](int x1, int y1, int x2, int y2)->int{
        assert(x2>=x1 && y2>=y1);
        int ans = a[x2][y2] - (x1>0?a[x1-1][y2]:0) - (y1>0?a[x2][y1-1]:0) + (y1>0 && x1>0?a[x1-1][y1-1]:0);
        return ans;
    };
    vector<int> up(WIDTH+1, 0), down(WIDTH+1, 0), left(WIDTH+1, 0), right(WIDTH+1, 0);
    //2d kadane algo, with dividng by i where is row i(top-bottom) or col i (left-right) since row i can init of itself provide contribution
    //we wnat to make sure that 1 takes any contrbution there, thus have only top start on i and bottom be strictely bigger, same for right(on I)/left(less than)

    for(int top = 0; top<WIDTH; top++){
        for(int bottom = top; bottom<WIDTH; bottom++){
            int lf = 0;
            for(int rows = 0; rows<WIDTH; rows++){
                int cur_sum = getRec(top, lf, bottom, rows);
                int this_row = getRec(top, rows, bottom, rows);
                if(cur_sum<this_row){
                    lf = rows;
                    if(top != 0) down[top-1] = max(down[top-1], this_row);
                    up[bottom] = max(up[bottom], this_row);
                    if(rows+1 != WIDTH){
                        left[rows+1] = max(left[rows+1], this_row);
                    }
                    right[lf] = max(right[lf], this_row);
                }else{
                    if(top != 0) down[top-1] = max(down[top-1], cur_sum);
                    up[bottom] = max(up[bottom], cur_sum);
                    if(rows+1 != WIDTH){
                        left[rows+1] = max(left[rows+1], cur_sum);
                    }
                    right[lf] = max(right[lf], cur_sum);
                }
            }
        }
    }
    for (int i = 1; i < WIDTH; i++) {
        up[i] = max(up[i], up[i - 1]);
        left[i] = max(left[i], left[i - 1]);
    }
    for (int i = WIDTH - 2; i >= 0; i--) {
        down[i] = max(down[i], down[i + 1]);
        right[i] = max(right[i], right[i + 1]);
    }
    int ans = 0;
    for(int i =0; i<WIDTH; i++){

        ans = max(ans, up[i]+down[i]);
    }
    for(int i = 0; i<WIDTH; i++){

        ans = max(ans, left[i]+right[i]);
    }
    cout<<ans+ans1;

}
