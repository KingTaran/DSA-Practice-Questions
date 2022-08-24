class Solution {
public:
    int jump(vector<int>& A) {
        int n = A.size() ;
        vector<int>dp(n+1 , n + 1); 
        dp[0] = 0 ; 
        for(int i = 0 ; i< n ; i++){
            int start = i  ; 
            int end =  min(i + A[i] , n-1 );   
            for(int j = i ; j <=end  ; j++){
                dp[j] = min(dp[j] ,  dp[start] + 1  ) ; 
            }
        }
        return dp[n-1] == n + 1 ? -1 : dp[n-1]; 
    }
};