class Solution {
public:
    int numDistinct(string s, string t) {
        dp.resize(s.size() + 1 , vector<int> (t.size() + 1 , -1)); 
     return tabulization(  s  , t);    
    }
    private: 
    vector<vector<int>> dp ; 
    int func(string s ,string t ,int n ,int m ){
        if(m == 0 ){
            return 1; 
        }
        if(  n <= 0 ){
            return 0 ; 
        }
        if(dp[n][m] != -1){
            return dp[n][m] ; 
        }
        if(s[n-1] == t[m-1]){
            return dp[n][m] = func(s, t , n -1 , m-1) + func(s , t , n-1 , m ); 
        }
        else{
        return dp[n][m] = func(s , t , n-1 , m );  }
    }
    int tabulization(string &s , string &p ){
        int n = s.size()  ; 
        int m = p.size()  ;
       vector<vector<double>> t (n+1 , vector<double>(m+1, 0 )); 
        for(int i = 0 ; i<= n ; i++){
            t[i][0] = 1; 
            
        }
        for(int i = 1 ; i <= n  ; i++ ){
            for(int j =1 ; j <=m ; j++  ){
                if(s[i-1] == p[j-1]){
                    t[i][j]  = t[i-1][j-1] + t[i-1][j]; 
                }
                else{
                    t[i][j] = t[i-1][j];  
                }
            }
        }  
       
        return t[n][m]; 
    }
    
};