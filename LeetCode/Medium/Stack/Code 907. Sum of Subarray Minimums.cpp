//beats 99.63%
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9+7; //mod int
        int result = 0; //keep track of result
        stack<int> st; //stack: push all the subarrays that have i as the smallest index, when we get to one that is smaller push it onto becuz all future subarrays will have that as its min
        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int j = st.top();// cur variable
                st.pop();
                int k = st.empty() ? -1 : st.top(); //next smallest one (i-j the ones thru i-j where j is the smallest, and j-k where j is the smallest)
                result += static_cast<long long>(arr[j]) * (i - j) * (j - k) % MOD;
                result %= MOD;
            }

            st.push(i);
        }
        // do it again but for any remaining its simply the full array
        while (!st.empty()) {
            int j = st.top();
            st.pop();
            int k = st.empty() ? -1 : st.top();
            result += static_cast<long long>(arr[j]) * (arr.size() - j) * (j - k) % MOD;
            result %= MOD;
        }

        return static_cast<int>(result);
    }
};
