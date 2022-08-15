class Solution {
public:
    int func(vector<int> v ,int i , int buy , int n , vector<vector<long long>>&dp){
        if(i >= n ){
            return 0 ; 
        }
        if(dp[i][buy] != -1){
            return dp[i][buy]; 
        }
        if(buy){
            return dp[i][buy] = max( -v[i] + func(v , i + 1 , 0, n , dp) ,func(v , i + 1 , 1, n , dp) ); 
        }
        else{
           return  dp[i][buy] = max( v[i] + func(v , i + 2 , 1, n , dp) ,func(v , i + 1 , 0, n , dp) ); 
        }
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<long long>>dp(prices.size() + 1 , vector<long long>(2 , -1)); 
        return func(prices , 0 , 1 , prices.size() , dp); 
    }
};