class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> hsh;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            hsh[arr[i]]++;
        }
        vector<int> a;
        int count = 0;
        for(auto i: hsh){
            count++;
            a.push_back(i.second);
        }
        sort(a.begin(), a.end());
        for(int i = 0; i<a.size(); i++){
            if(k>=a[i]){
                k-=a[i];
                count--;
            }else{
                break;
            }
        }
        return count;
    }
};
