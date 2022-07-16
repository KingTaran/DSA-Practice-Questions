class Solution {
public:
    int func(vector<int> v  ,int n , vector<int > &dp ){
        if(n <= 0 ){
            return 0 ; 
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int res1  =  v[n-1] +  func( v, n-2 ,dp  ) ; 
        int res2 = func(v , n -1 , dp )  ;
        dp[n] = max(res1 , res2 ) ; 
        return dp[n ] ; 
        
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(10000 , -1 ); 
        return func(nums , nums.size() ,dp ); 
    }
};