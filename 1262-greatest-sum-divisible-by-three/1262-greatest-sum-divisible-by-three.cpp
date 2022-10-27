class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        dp.resize(nums.size()+ 1 , vector<int>( 4, -1)) ;  
                  
        int res =  func(nums , 0 , 0 ); 
        if(res < 0 ){
            return 0 ; 
        }
        return res ; 
      
        
    }
private: 
    vector<vector<int>> dp; 
    int func(vector<int> & v  , int i , int mod ){
        if(i == v.size()){
            if(mod == 0 ){
                return 0 ; 
            }
            return INT_MIN  ; 
        }
        if(dp[i][mod]!= -1){
            return dp[i][mod ]; 
        }
        int x  = v[i]% 3; 
        x = (x + mod)%3; 
        return dp[i][mod] =  max(func(v , i + 1 , mod) , v[i] + func(v , i + 1 , x ) );  
        
        
        
    }
};