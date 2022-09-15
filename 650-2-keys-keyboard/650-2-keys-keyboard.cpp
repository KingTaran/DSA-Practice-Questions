class Solution {
public:
    int func( int i , int n ,int l ,  vector<vector<int>> &dp  ){ 
        
         if(i > n ){
             return 1000000 ; 
         }
        if(!(n - i)){
            return 0 ; 
        }
        if(dp[i][l]){
            return dp[i][l]; 
        }
        int copy = 2 + func( i + i , n , i , dp );
        int paste = 1 + func(i + l , n , l  , dp ); 
        return dp[i][l] = min (copy , paste); 
    }
    int minSteps(int n) {
        vector<vector<int>>dp ( n + 1 , vector<int> ( n + 1 , 0)); 
        return n > 1 ? 1 +func(1 , n , 1 , dp ) : 0  ; 
    }
};



