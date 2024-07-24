class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int numsSize = nums.size(); // Number of elements in nums
        vector<pair<int, int>> mappedAndIndexPairs(numsSize); // Pair to store the mapped value and original index

        // Transform each number as per the mapping and associate it with its original index
        for (int i = 0; i < numsSize; ++i) {
            int originalNum = nums[i];
            int mappedNum = originalNum == 0 ? mapping[0] : 0; // If the number is 0, directly map it
            int placeValue = 1; // Represents the place value in the mapped number

            // Decompose the number into its digits and transform it according to the mapping
            while (originalNum > 0) {
                int digit = originalNum % 10; // Get the last digit
                mappedNum += placeValue * mapping[digit]; // Map the digit and add to the mapped number
                originalNum /= 10; // Remove the last digit from the original number
                placeValue *= 10; // Move to the next place value
            }

            // Save the pair of mapped number and original index
            mappedAndIndexPairs[i] = {mappedNum, i};
        }

        // Sort the pairs. The order is firstly by the mapped number, and then by the original index
        sort(mappedAndIndexPairs.begin(), mappedAndIndexPairs.end());

        // Extract the numbers from the sorted pairs, preserving the new order
        vector<int> sortedNums;
        for (auto& pair : mappedAndIndexPairs) {
            sortedNums.push_back(nums[pair.second]);
        }

        // Return the sorted numbers as per the jumbled mapping order
        return sortedNums;
    }
};
