class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;
    int t;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> zt;
        dfs(0, 0, zt, candidates, target);
        return ans;
    }

    void dfs(int start, int cur_sum, vector<int>& cur_v, vector<int>& candidates, int target) {
        if (cur_sum == target) {
            ans.push_back(cur_v);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }

            if (cur_sum + candidates[i] > target) {
                break; // Stop further exploration since the candidates array is sorted
            }

            cur_v.push_back(candidates[i]);
            dfs(i + 1, cur_sum + candidates[i], cur_v, candidates, target);
            cur_v.pop_back();
        }
    }
};
