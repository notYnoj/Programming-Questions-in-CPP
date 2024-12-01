class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> s;

        for(int i = 0; i<arr.size(); i++){
            if(s.find(arr[i]*2)!=s.end()){
                return true;
            }
            if(arr[i]%2 == 0 && s.find(arr[i]/2) !=s.end()){
                return true;
            }
            s[arr[i]] = 1;
        }
        return false;
    }
};  
