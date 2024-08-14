class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
      vector <int> a=nums;
      sort(a.begin(),a.end());
      int l=-1; int r=1e6+2;
      while(l+1<r){
        int mid=(l+r)/2;
        long long sum=0;
        int lst=0;
        for (int i=0; i<a.size(); i++){
          while(lst<i){
            if (a[i]-a[lst]<=mid) break;
            lst++;
          }
          sum+=i-lst;
        }
        if (sum>=k) r=mid;
        else l=mid;
      }
      return r;
    }
};
