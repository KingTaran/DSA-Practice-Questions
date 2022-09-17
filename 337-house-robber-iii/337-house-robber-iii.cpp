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
    int rob(TreeNode* root) {
       return func(root ); 
    }
    private:
    unordered_map<TreeNode*, int> dp;
    int func(TreeNode *root  ){
         if(!root) return 0;
        
        if(dp.count(root )  )
        {
            return dp[root ]; 
        }        
        int dontRob = func(root -> left) + func(root -> right), robRoot = root -> val;
        if(root -> left) robRoot += func(root -> left -> left) + rob(root -> left -> right);
        if(root -> right) robRoot += func(root -> right -> left) + func(root -> right -> right);
        return dp[root] =  max(dontRob, robRoot);
    }
};