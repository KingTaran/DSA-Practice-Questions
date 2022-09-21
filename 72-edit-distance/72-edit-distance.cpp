// Kaffi accha question hai 
// kaafi saare concepts use ho rahe hai ek saath 


class Solution {
public:
    int minDistance(string x , string y) {
        int n = x.size() + 1 ; int m = y.size() + 1 ; 
        dp.resize( n , vector<int> (m , -1 )) ; 
     return func(x , y , x.size()-1  , y.size() -1);    
    }
    
    
private : 
    vector<vector<int>> dp  ; 
    int func(string &s , string &p , int n , int m ){
        if(n < 0 ){
            return m  +1 ; 
        }
        if(m < 0 ){
            return n + 1; 
        }
        if(dp[n][m] != -1){
            return dp[n][m]; 
        }
        if(s[n] == p[m]){
            return dp[n][m] = func(s , p , n -1 , m-1); 
        }
        return dp[n][m] = 1 + min(func(s , p , n-1 , m )  , min (func(s, p , n-1 , m-1) , func(s , p , n , m-1)) ); 
        
        
    }
};