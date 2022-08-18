class Solution {
public:
    int func(vector<int>& days , vector<int> & cost , int index , vector<int> &dp){
        if(index >= days.size()){
            return 0 ; 
        }
        if(dp[index]  != -1){
            return dp[index]; 
        }
        int opt1 = cost[0] + func(days , cost , index + 1, dp ) ;
        int i = 0  ; 
        for( i = index ; i<days.size() && days[i] < days[index] + 7 ; i++ ); 
        
        int opt2 = cost[1] + func(days , cost , i, dp   ); 
        for( i = index ; i<days.size() && days[i] < days[index] + 30 ; i++ );      
        int opt3 = cost[2] + func(days , cost , i , dp ); 
        dp[index] =  min(opt1 , min(opt2 , opt3)); 
        return dp[index]; 
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp (days.size() + 1 , -1); 
        
        
     return func(days , costs , 0  , dp ); 
    }
};