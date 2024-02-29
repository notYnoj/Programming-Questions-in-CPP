class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        //even indexed = odd increasing
        // odd = even decreasing
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            if(level % 2 == 0){
                int prev = -1;
              //go thru each one only special case is the first one
                for(int i= 0; i<size; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                  //if its -1 aka starting
                    if(prev == -1){
                        prev = cur->val;
                      //check if its not its proper even/odd
                        if(cur->val % 2 == 0){
                            return false;
                        }
                    }
                  //check if not decreasing/increasing + proper even/odd 

                    else if(cur->val<=prev || cur->val%2 == 0){
                        return false;
                    }else{
                      //update prev

                        prev = cur->val;
                    }
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
            }else{
                int prev = -1;
                for(int i= 0; i<size; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    if(prev == -1){
                        prev = cur->val;
                    //check if its not its proper even/odd
                        if(cur->val % 2 != 0){
                            return false;
                        }
                    }
                      //check if not decreasing/increasing + proper even/odd 
                    else if(cur->val>=prev||cur->val%2 == 1){
                        return false;
                    }else{
                      //update prev
                        prev = cur->val;
                    }
                  //push its children
                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }

            }
          //add a level
            level++;
        }
      //return true if not flagged by false
        return true;
    }
};
