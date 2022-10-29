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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == 0){
            return 0 ; 
        }
        if(root ->val == sum &&root ->left  == 0 && root ->right == 0 ){
            return 1 ; 
        }
        return hasPathSum(root ->left , sum - root ->val  ) || hasPathSum(root ->right , sum - root ->val ) ;
    }
};