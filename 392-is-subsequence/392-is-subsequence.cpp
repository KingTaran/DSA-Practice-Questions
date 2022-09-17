class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0  ){
            return 1 ; 
        }
        if(t.size() == 0 ){
            return 0 ; 
        }
        vector<vector<int>>dp (s.size() + 1 , vector<int>(t.size() + 1 , -1)); 
        return func(s, t, s.size()-1, t.size()-1  , dp ) ; 
    }
private : 
    bool func(string &s , string &t  , int i , int j , vector<vector<int>>&dp  ){
       if(i < 0 ){
           return 1; 
       }
       if(i >= 0 && j < 0 )
       {
           return 0 ; 
       }
        
       if(dp[i][j] != -1){
           return dp[i][j]; 
       }
        bool f1 = 0  ; 
        bool f2  = 0 ; 
        if(s[i] == t[j]){
            f1= func(s , t , i-1 , j - 1 , dp ); 
        }
        else{
            f2 =  func(s , t , i , j - 1 ,dp ); 
        }
        return dp[i][j] = f1 || f2 ; 
  //  i   
  // abc 
  //     j       
  // ahbgdc
        
        
    }
};