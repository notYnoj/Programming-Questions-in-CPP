#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<=4){
        cout<<-1;
    }else {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<int> ans(n);
        if (n % 2 == 0) {
            //0 1 2 3 4 5 6
            //0 2 4 6 1 3 5
            int temp = 0;
            for (int i = 0; i < n; i += 2) {
                ans[temp] = nums[i];
                temp++;
            }
            for (int i = 1; i < n; i += 2) {
                ans[temp] = nums[i];
                temp++;
            }
            swap(ans[n - 1], ans[n - 2]);
        } else {
            int temp = 0;
            for (int i = 0; i < n; i += 2) {
                ans[temp] = nums[i];
                temp++;
            }
            for (int i = 1; i < n; i += 2) {
                ans[temp] = nums[i];
                temp++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
    }
}
