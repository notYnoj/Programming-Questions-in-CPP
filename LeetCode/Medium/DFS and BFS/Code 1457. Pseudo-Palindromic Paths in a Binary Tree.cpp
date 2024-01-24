/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ios_base::sync_with_stdio(false); //fast
        cin.tie(0);
        cout.tie(0);
        int result = 0;
        map<int, int> mp;
        dfs(root, mp, result);
        return result;
    }
private:
    void dfs(TreeNode* root, map<int, int>& mp, int& result){
        if(!root->left && !root->right){
            mp[root->val]++;
            if(palindrome(mp)){
                result++;
            }
        }else{
            mp[root->val]++;
            if(root->left){
               dfs(root->left, mp, result); 
            }
            if(root->right){
                dfs(root->right, mp, result);
            }
            if(mp[root->val] == 0){
                mp.erase(root->val); // if negative sad
            }

        }
        mp[root->val]--; //make sure to subtract as passing in by reference!

    }

    bool palindrome(map<int, int> mp){
        int odd = 0;
        for(auto i: mp){
            cout<<i.first<<" "<< i.second<<"\n";
            if(i.second%2 == 1){
                odd++;
            }
            if(odd>1){
                return false;
            }
        }
        return true;
    }
};
