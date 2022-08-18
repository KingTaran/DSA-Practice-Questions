class Solution {
public:
    int func(vector<int> &coins , int amount , vector<vector<int>>& dp  ){
        if(amount == 0){
            return 0 ; 
        }
        if(amount < 0 ){
            return INT_MAX -1 ; 
        }
        
        int coin = INT_MAX-1; 
        int res ; 
        for(int i = 0 ; i< coins.size() ; i++)
        {
            if(dp[i][amount] != -1){
                res = dp[i][amount]; 
            }
            else{
             res = func(coins , amount - coins[i], dp ); 
            dp[i][amount] = res ; } 
            if(res != INT_MAX -1){
                coin = min(coin , res + 1 ); 
            }
        }
        return coin; 
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1 , vector<int>(amount + 1 , -1)); 
        int op =  func(coins , amount ,dp  ); 
        if(op == INT_MAX-1){
            return -1; 
        }
        return op ; 
    }
};