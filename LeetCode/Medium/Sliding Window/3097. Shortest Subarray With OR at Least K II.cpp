class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        long long l = 0, r = 0;
        long long ans = LLONG_MAX;
        vector<int> bits(32, 0);

        while (r < nums.size()) {
            // Process the current element to add bits to the window
            long long cur = nums[r++];
            int bit = 0;

            while (cur > 0) {
                if (cur % 2) {
                    bits[bit]++;
                }
                cur >>= 1;
                bit++;
            }

            // Calculate the current value of `nw` from bits
            long long nw = 0;
            for (int i = 0; i < 32; i++) {
                if (bits[i] > 0) {
                    nw += (1LL << i);
                }
            }

            // Shrink window from the left if `nw` is at least `k`
            while (l < r && nw >= k) {
                ans = min(ans, r - l);
                
                // Remove bits for nums[l] as we slide the window
                long long leftNum = nums[l++];
                bit = 0;
                while (leftNum > 0) {
                    if (leftNum % 2) {
                        bits[bit]--;
                    }
                    leftNum >>= 1;
                    bit++;
                }

                // Recalculate `nw` after removing the left element
                nw = 0;
                for (int i = 0; i < 32; i++) {
                    if (bits[i] > 0) {
                        nw += (1LL << i);
                    }
                }
            }
        }

        return (ans == LLONG_MAX) ? -1 : ans;
    }
};
