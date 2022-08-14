class Solution {
public:
    int mod = 1e9 + 7 ; 
     int helper(int i , string &s , vector<int> &dp ){
         if(s[i] == '0'){
             return 0 ; 
         }
         if(i >= s.size()-1){
             return 1; 
         }
         
         if(dp[i] != -1){
             return dp[i] ; 
         }
         if(i + 1 < s.size() && (s[i] == '1' || (s[i] == '2' && (s[i + 1] >=48 && s[i+ 1] <= 54 )))) {
             dp[i] = helper(i + 1 , s , dp ) + helper(i + 2 , s , dp );   
             return dp[i]  ; 
         }
         else{
             dp[i] = helper(i + 1 , s ,dp );
             return dp[i]  ; 
             
         }
         
         
         
     }
    
    
    int numDecodings(string s) {
        vector< int> dp (s.size() + 1 , -1); 
        return helper(0 , s , dp ); 
    }
};