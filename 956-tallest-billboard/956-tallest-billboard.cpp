class Solution {
public:
    
    int tallestBillboard(vector<int>& rods) {
        int sum  = 0 ; 
        sum = accumulate(rods.begin()  , rods.end() , sum ); 
        dp.resize(rods.size()  + 1  , vector<int> (sum + 1 , -1)); 
        return func(rods , 0 , 0 , 0  )/2 ; 
    }
private : 
    vector<vector<int>> dp ; 
    int func(vector<int> & v , int left  , int right , int i  ){
        if(i == v.size()){
            if(left == right){
                return 0;
            }
            return -10000;
        }
       if(dp[i][abs(left - right) ] != -1){
           return dp[i][abs(left-right)]; 
       } 
        
        
        return dp[i][abs(left-right)] = max(func(v ,left , right , i + 1 ) , max(v[i] + func(v, left + v[i] , right , i + 1) ,v[i] + func(v, left  , right + v[i] , i + 1)  )); 
        
        
        
        
    } 
};