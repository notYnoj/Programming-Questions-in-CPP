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
    auto getRec= [=](int x1, int y1, int x2, int y2)->int{
        assert(x2>=x1 && y2>=y1);
        int ans = a[x2][y2] - (x1>0?a[x1-1][y2]:0) - (y1>0?a[x2][y1-1]:0) + (y1>0 && x1>0?a[x1-1][y1-1]:0);
        return ans;
    };
    vector<int> up(WIDTH), down(WIDTH), left(WIDTH), right(WIDTH);
    

}
