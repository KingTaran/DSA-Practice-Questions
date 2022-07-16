class Solution {
public:
    int func(int n   ){
        if(n <= 2){
            return 1; 
        }
        if(n==3){
            return 2; 
        }
        if(n ==4){
            return 4; 
        }
       int dp[n + 1]; 
        fill(dp , dp + n + 1 , 0 ); 
        dp[1] =1 ; 
         dp[2] = 1; 
        dp[3] = 2; 
        dp[4] = 4 ; 
        for(int i = 5 ; i <= n ; i++){
            dp[i] = 3*max(dp[i-3] , i -3); 
        }
        return dp[n] ; 
    }
    int integerBreak(int n) {
        // vector<int> dp(n+1 , -1); 
        
        return func(n ); 
    }
};