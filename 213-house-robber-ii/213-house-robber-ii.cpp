class Solution {
public:
    
    int func(vector<int>  & v    , int i  , int j  , vector<vector<long long int >>&dp  ){
        if(i >= j){
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        int choice1 = v[i] + func(v , i + 2 ,j ,dp  ); 
        int choice2 = func(v , i + 1  , j ,dp ); 
        return dp[i][j]  = max(choice1 ,choice2); 
        
        
    }
    
    int rob(vector<int>& v) {
        if(v.size() == 1 ){
            return v[0]; 
        }
        vector<vector<long long int >> dp (v.size() + 1 , vector<long long int >(v.size() + 1 , -1)); 
        int res1 = func(v , 1  , v.size()  , dp );
        int res2 = func(v , 0 , v.size() -1 , dp ); 
        return max(res1 , res2 ); 
        
    }
};