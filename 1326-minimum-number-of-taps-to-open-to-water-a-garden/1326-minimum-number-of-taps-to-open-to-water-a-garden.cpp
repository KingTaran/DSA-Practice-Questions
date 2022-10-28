
class Solution {
public:
    
    int minTaps(int n, vector<int>& A) {
     vector<int> dp(n + 1 , n+ 2);  
        dp[0] = 0 ; 
        for(int i = 0 ; i<= n ; i++){
            int left = max(0  , i - A[i]); 
            int right = min(i + A[i] , n); 
            for(int j = left ; j <= right ; j ++){
                dp[j] = min(dp[j] , dp[left] + 1 ); 
            }
        }
        return dp[n] < n +2 ? dp[n] : -1; 
    }
};