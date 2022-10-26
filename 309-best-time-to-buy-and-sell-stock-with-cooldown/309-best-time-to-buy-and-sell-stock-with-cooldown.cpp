class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size() + 1 , vector<long long> (2 , -1)); 
        return func(prices , 0 , 1); 
    }
private : 
    vector<vector<long long >> dp ; 
    int func(vector<int> & v  ,int  i ,  bool buy ){
        if(i >= v.size() ){
            return 0 ; 
        }
        if(dp[i][buy] != -1){
            return dp[i][buy]; 
        }
        
        if(buy){
            return dp[i][buy] =  max(-v[i]  + func(v , i+1  , 0 ) , func(v , i+1 , 1  )); 
        }
        else{
            return dp[i][buy] =  max(v[i] + func(v , i + 2 , 1 ) , func(v , i + 1 , 0)); 
        }
        
    }
};