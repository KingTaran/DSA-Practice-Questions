class Solution {
public:
        int helper(int n  , vector<int> &a  ){
        int dp[n+ 1 ]; 
        fill(dp , dp + n + 1 , INT_MAX); 
        dp[0] = INT_MIN ; 
    for(int i = 0  ; i < n ; i++){
        int idx = upper_bound(dp ,dp + n + 1 , a[i] ) -dp; 
        if(a[i] > dp[idx -1] && a[i] < dp[idx] ){
            dp[idx] = a[i] ; 
        }
    }
    
    for(int i = n ; i>=0  ; i --){
        if(dp[i]!= INT_MAX ){
            return i ; 
        }
    }
            return 0 ; 
        }
    
    int lengthOfLIS(vector<int>& nums) {
        return helper(nums.size() , nums ); 
    }
};