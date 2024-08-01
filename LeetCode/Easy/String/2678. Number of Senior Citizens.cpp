#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0; i < details.size(); i++){
            // Get the substring that contains the age information
            string ageStr = details[i].substr(11, 2);
            // Convert the substring to an integer and check if it is greater than 60
            if(stoi(ageStr) > 60){
                ans++;
            }
        }
        return ans;
    }
};
