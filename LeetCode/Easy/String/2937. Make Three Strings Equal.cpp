class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = 101;
        n = min((int)s1.size(), n);
        n = min((int)s2.size(), n);
        n = min((int)s3.size(), n);
        
        for(int i = 0; i<min(n,1); i++){
            if(s1[i] != s2[i] || s1[i] != s3[i] || s2[i]!=s3[i]){
                return -1;
            }
        }
        int t = 1;
        for(int i = 1; i<n; i++){
            if(s1[i] != s2[i] || s1[i] != s3[i] || s2[i]!=s3[i]){
               break;
            }else{
                t++;
            }
        }
        int ans = 0;
        ans+=s1.size()-t;
        ans+=s2.size()-t;
        ans+=s3.size()-t;
        return ans;


    }
};
