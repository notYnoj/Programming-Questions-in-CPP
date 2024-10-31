class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m = robot.size(), n = factory.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        
        for (int i = 0; i < m; i++) {
            dp[i][n] = LLONG_MAX;
        }
        
        for (int j = n - 1; j >= 0; j--) {
            long long prefix = 0;
            deque<pair<int, long long>> qq;
            qq.push_back({m, 0});
            
            for (int i = m - 1; i >= 0; i--) {
                prefix += abs(robot[i] - factory[j][0]);
                
                while (!qq.empty() && qq.front().first > i + factory[j][1]) {
                    qq.pop_front();
                }
                
                while (!qq.empty() && qq.back().second >= dp[i][j + 1] - prefix) {
                    qq.pop_back();
                }
                
                qq.push_back({i, dp[i][j + 1] - prefix});
                dp[i][j] = qq.front().second + prefix;
            }
        }
        
        return dp[0][0];
    }
};
