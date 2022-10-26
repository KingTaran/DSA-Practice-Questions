class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1  , 0 ); 
        for(int i =1 ; i<=n ;i++){
            dp[i] = i ;
        }
        int count =1; 
       while(count * count <= n ){
           int sq = count *count ; 
           for(int i = sq ; i<=n ; i++){
               dp[i] = min(dp[i] , dp[i-sq] + 1 ); 
           }
           count += 1; 
       }
        return dp[n ] ; 
    }
};