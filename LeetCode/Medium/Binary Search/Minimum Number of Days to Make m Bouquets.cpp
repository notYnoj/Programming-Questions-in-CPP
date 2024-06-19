class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        long long tz = (long long)m*(long long)k;
        if (tz > n) {
            return -1;
        }
        
        int l = INT_MAX;
        int r = INT_MIN;
        for (int i = 0; i < n; ++i) {
            l = min(b[i], l);
            r = max(b[i], r);
        }
        
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool can = false;
            int c = 0;
            int pos = 0;
            
            while (pos < n && c < m) {
                int t = true;
                if (pos + k > n) {
                    break;
                }
                
                for (int i = 0; i < k; ++i) {
                    if (b[pos + i] > mid) {
                        pos = pos + i + 1;
                        t = false;
                        break;
                    }
                }
                
                if (t) {
                    ++c;
                    pos = pos + k;
                }
            }
            
            if (c >= m) {
                can = true;
            }
            
            if (can) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
