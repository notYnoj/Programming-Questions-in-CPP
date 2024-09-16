class Solution {
public:
    int findMinDifference(vector<string>& tP) {
        vector<int> times;
        for(string i: tP) {
            // Concatenate characters as strings
            string s = string(1, i[0]) + string(1, i[1]); // Hours as string
            string m = string(1, i[3]) + string(1, i[4]); // Minutes as string

            int s1 = stoi(s);  // Convert hours to int
            int m1 = stoi(m);  // Convert minutes to int
            int cur = s1 * 60 + m1;  // Convert to total minutes
            times.push_back(cur);
        }
        sort(times.begin(), times.end());
        times.push_back(times[0]);
        int ans = INT_MAX;
        for(int i = 0; i<times.size()-1; i++){
            int tz = ((times[i+1] - times[i]) % 1440 + 1440) % 1440;
            cout<<tz<<'\n';
            ans = min(ans, tz);
        }
        return ans;
    }
};
