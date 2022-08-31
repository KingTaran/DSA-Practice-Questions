class Solution {
public:
    int func(vector<string> &v , int i , int m , int n , vector<vector<vector<int>>>&dp ){
        if(i >= v.size()){
            return 0 ; 
        }
        if(dp[m][n][i] != -1){
            return dp[m][n][i]; 
        }
        string x = v[i] ; 
        int countz = 0 ; 
        int counto  =  0; 
        for(auto idx : x ){
            if(idx == '0'){
                countz ++ ; 
            }
            if(idx =='1'){
                counto ++; 
            }
        }
        if((m - countz) >= 0 && (n - counto) >= 0 ){
         return dp[m][n][i] =  max( 1 + func(v , i + 1 , m - countz , n - counto , dp ) , func(v , i + 1 , m , n , dp  )); 
        }
        
        return dp[m][n][i] =  func(v , i + 1 , m , n , dp); 
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size() + 1 , -1)));
// x = number of elements in 1D vector
// y = number of 1D vectors in 2D vector
// z = number of 2D vectors in 3D vector
// value = value for each element
        return func(strs , 0 , m , n ,dp) ; 
    }
};