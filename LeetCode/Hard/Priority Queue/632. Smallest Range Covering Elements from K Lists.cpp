class compare{
  public:
  bool operator()(pair<int,pair<int,int>>a ,pair<int,pair<int,int>>b){
      return a.first>b.first;
  }  
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> pq;

       int maxi= INT_MIN;
       for(int i=0; i<nums.size(); i++){
        pair<int,pair<int,int>> p= make_pair(nums[i][0], make_pair(i,0));
        pq.push(p);
        maxi= max(maxi,p.first);
       }

       int ansStart= pq.top().first;
       int ansEnd= maxi; 

       while(!pq.empty()){
        int topData= pq.top().first;
        pair<int,int> coordinates= pq.top().second;
        int row= coordinates.first;
        int col= coordinates.second;
        pq.pop();

        if((maxi-topData)<(ansEnd-ansStart)){
            ansStart= topData;
            ansEnd= maxi;
        }
        if(col+1<nums[row].size()){
           pair<int,pair<int,int>> p= make_pair(nums[row][col+1], make_pair(row,col+1));
           pq.push(p);
           maxi= max(maxi,p.first);
        
        }
        else{
            break;
        }
       }
       vector<int> ans;
       ans.push_back(ansStart);
       ans.push_back(ansEnd);
       return ans;
    }
};
