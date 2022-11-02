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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums , 0 , nums.size() -1); 
    }
    
private : 
   
    TreeNode*  func(vector<int> &v  , int i , int j ){

        if(i > j ){
            return 0; 
        }
        int mid = (i+j)/2;
       TreeNode *  head =  new TreeNode(v[mid]) ;
        head ->left = func(v , i , mid -1); 
        head ->right = func(v , mid + 1 , j ); 
      
        return head; 
        
    }

};