class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> hash(205, 0);
        for(int i: nums){
            hash[i+100]++;
        }
        vector<pair<int, int>> sorted;
        for(int i = 0; i < 205; i++){
            if(hash[i]!=0){
                sorted.push_back({hash[i], i-100});
            }
        }
        sort(sorted.begin(), sorted.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;  // Sort by frequency in ascending order
            }
            return a.second > b.second;  // If frequencies are equal, sort by number in descending order
        });
        
        // Reconstruct the result
        vector<int> result;
        for (const auto& p : sorted) {
            result.insert(result.end(), p.first, p.second);
        }
        return result;
    }
};
