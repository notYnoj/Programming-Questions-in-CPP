class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      //hsh to contain arr[i]:count
        map<int, int> hsh;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            hsh[arr[i]]++;
        }
        //any number n can at most have occurence of arr.size(), thus we create an array with n+1 elements due to 0 indexing
        vector<bool> temp(n+1, false);
        for(auto i: hsh){
          //if we encounter it again return false;
            if(temp[i.second]){
                return false;
            //set the amount equal to true aka used
            }else{
                temp[i.second] = true;
            }
        }
      //return true if no count has the same
        return true;
    }
};
