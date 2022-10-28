class Solution {
public:
    // This question is the base question for Min number of Taps to water the garden 
    // So it is Important 
    int jump(vector<int>& A) {
        int n = A.size() ;
        vector<int>dp(n+1 , n + 1); 
        dp[0] = 0 ; 
       for(int i = 0 ; i< n ; i ++ ){
           int start = i ; 
           int end = min(i + A[i] , n-1); 
           for(int j = start ; j <= end ; j++){
               dp[j] = min(dp[j] , dp[start] + 1 ); 
               // cout<< dp[j] <<" " ; 
           }
       }
        return dp[n-1] == n + 1 ? -1 : dp[n-1]; 
    }
};