class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        long long ans = 0;
        for(int i = 0; i<q.size(); i++){
            ans+=q[i];
        }
        sort(q.begin(), q.end());
        int l = 1;
        int r = INT_MAX-1;
        while(l<r){
            long long mid = (l+r)/2;
            int buckets = n;
            bool good = true;
            for(int i = 0; i<q.size();i++){
                if(q[i]%mid == 0){
                    buckets-=(q[i]/mid);
                }else{
                    buckets-=(q[i]/mid);
                    buckets--;
                }
                if(buckets<0){
                    good = false;
                    break;
                }
            }
            if(good){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
