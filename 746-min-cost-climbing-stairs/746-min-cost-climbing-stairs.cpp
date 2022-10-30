class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return func(cost , cost.size()); 
    }
private : 
    int func(vector<int> & v , int n  ){
        vector<int>dp(n + 1); 
        for(int i = 2 ; i<= n ; i++){
            int onestep = dp[i-1] + v[i-1]; 
            int twostep = dp[i-2] + v[i-2]; 
            dp[i] = min(onestep , twostep); 
        }
        return dp[n];
    }
};