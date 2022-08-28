class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp ( 3  ); 
        for(auto x : nums ){
            for(auto i : vector<int>  (dp) ){
                dp[(i + x ) % 3] =  max( dp[ (i + x ) % 3]  ,  i + x   ); 
            }
        }
        
        return dp[0] ; 
    }
};