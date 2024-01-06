class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = jobs[i][2];
            int prevNonOverlap = findPrevNonOverlap(jobs, i);
            if (prevNonOverlap != -1) {
                dp[i] = max(dp[i], dp[prevNonOverlap] + jobs[i][2]);
            }
            if (i > 0) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
        }

        return dp[n - 1];
    }

private:
    int findPrevNonOverlap(const vector<vector<int>>& jobs, int currentJob) {
        int low = 0, high = currentJob - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (jobs[mid][1] <= jobs[currentJob][0]) {
                if (jobs[mid + 1][1] <= jobs[currentJob][0]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
