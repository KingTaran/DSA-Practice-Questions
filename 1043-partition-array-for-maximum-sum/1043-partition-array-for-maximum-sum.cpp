class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ; 
        vector<int> dp ( n + 1  ); 
        // dp[0] = 0 ; dp[1] = arr[ ; 
        for(int i = 1 ; i<= n ; ++i){
            int curr_max = 0 , best = 0 ; 
            for(int j = 1   ; j <=k && (i - j) >= 0   ; ++j){
                curr_max = max(curr_max , arr[i-j]); 
                best = max(best ,dp[i-j] + curr_max* j  ); 
            }
            dp[i] = best; 
        }
//         for(auto  x : dp ){
//             cout<< x <<" " ; 
//         }
        
        
        return dp[n] ; 
    }
};