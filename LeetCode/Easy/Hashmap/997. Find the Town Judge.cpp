class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      //use two hashmaps, one counter and one bool
        int needed = n-1;
        vector<int> t(n+1, 0);
      //technically still O(N) SC since for big O notation coefficents dont matter but -> O(2N) in reality
        vector<bool> check(n+1,true); 
        for(auto i: trust){
          //add 1 to placedT (placed Trust)
            int placedT = i[1];
            int trustee = i[0];
            t[placedT]++;
          //the trustee has trusted someone so make it false
            check[trustee] = false;
            
        }
        for(int i = 1; i<=n; i++){
          //check for question conditions if correct than return that index
            if(t[i] == needed && check[i]){
                return i;
            }
        }
      //else if there is none return -1
        return -1;
    }
};
// inital solve: 0:46 

//advanced less space solution - 1:41

/*class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> needed(n+1, 0);
        //same idea simply less space O(N) TC and O(N) SC
        for(int i = 0; i<trust.size(); i++){
            needed[trust[i][1]]++;
            needed[trust[i][0]]--;
        }
        for(int i = 1; i<=n; i++){
            if(needed[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};*/
