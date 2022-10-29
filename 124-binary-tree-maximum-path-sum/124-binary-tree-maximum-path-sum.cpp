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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN ; 
        func(root , res ); 
        return res ;
    }
    
private : 
    int func(TreeNode * root , int &res ){
        if(root == 0 ){
            return 0 ; 
        }
        int l = func(root ->left , res ) ; 
        int r = func(root ->right , res ); 
        
        int tempans =  max(max(l , r) + root ->val , root ->val ); 
        int ans = max(tempans , l + r + root ->val); 
         res = max(res , ans ); 
        return tempans  ; 
        
    }
};