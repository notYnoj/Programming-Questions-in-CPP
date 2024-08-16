class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0]; // Minimum element from the first array
        int max_val = arrays[0][arrays[0].size() - 1]; // Maximum element from the first array
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); i++) {
            int current_min = arrays[i][0];
            int current_max = arrays[i][arrays[i].size() - 1];
            
            // Calculate the maximum distance using the previous min and max values
            max_distance = max(max_distance, max(abs(current_max - min_val), abs(max_val - current_min)));
            
            // Update the global min and max values
            min_val = min(min_val, current_min);
            max_val = max(max_val, current_max);
        }
        
        return max_distance;
    }
};
