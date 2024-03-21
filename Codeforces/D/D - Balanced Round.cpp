#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
      //sort it, we can also always js remove everything to the right tahts why we have possible
        vector<int> possible;
      //usually it is js better to remove the left side
        for(int i = 1, j = 0; i<n; i++){
          //if we encounter something bigger than k
            if(arr[i]-arr[i-1]>k){
              //we establish a pointer at place j this will be where we "remove" 
                if(n-i<=i-j){
                    ans+= n-i;
                    break;
                }else {
                  //we must pushback our orignal greey answer + n-i
                    possible.push_back(n-i+ans);
                  //then we remove i-j 
                    ans += i - j;
                  //set j=i when we point it back to tell us hey remove from here
                    j = i;
                }
            }
        }
        if(possible.empty()) possible.push_back(INT_MAX);
      //get the min
        cout<<min(ans, *min_element(possible.begin(), possible.end()))<<"\n";
    }
}
