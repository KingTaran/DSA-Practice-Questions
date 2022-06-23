class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_number = INT_MAX ; 
        int max_number = INT_MIN ; 
        int max_profit = INT_MIN ; 
        int profit = 0 ; 
        for(int i = 0 ; i< prices.size()  ; i++){
            
            if(min_number > prices[i]){
                min_number = prices[i] ; 
            }
             profit = max(profit , prices[i] - min_number  ); 
            max_profit = max(profit , max_profit); 
        }
        return max(max_profit  ,0 ); 
        
    }
};