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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN ; 
        func(root , res ) ; 
        return res-1 ; 
    }
    
private:
    int func(TreeNode*root , int &res ){
        if(root == 0){
            return 0 ; 
        }
        int l  = func(root ->left , res ); 
        int r = func(root ->right , res ); 
        int tempans = 1 + max(l , r); 
        int ans = max(tempans , 1 +  l + r); 
        res = max(res , ans ); 
        return tempans ; 
        
        
    }
};