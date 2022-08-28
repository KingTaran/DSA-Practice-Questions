class Solution {
public:
    
    int func(vector<int> &v  , int index , int mod , vector<vector<int>>&dp ){
        if(index >= v.size()){
            if(mod == 0 ){
                return 0 ; 
            }
            return INT_MIN ; 
        }
        if(dp[index][mod] != -1){
            return dp[index][mod]; 
        }
        int f = v[index] % 3; 
        f=  (f + mod)%3; 
        
        return dp[index][mod] = max(v[index] + func(v , index + 1 , f ,dp ) ,  func(v , index + 1 , mod ,dp));
         
        
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()  +1 , vector<int> (3 , -1)); 
       return func(nums , 0 , 0 ,dp ); 
    }
    
    
    
    
    
    
    
     // int n = nums.size(); 
     //    vector<int> dp ( 3    , 0 );
     //   for(auto x : nums){
     //       for(auto i : vector<int> (dp)){
     //           dp[(i+ x ) % 3] = max(i + x ,dp[(i+ x ) % 3] );
     //       }
     //   }
     //    return dp[0] ; 
};

















