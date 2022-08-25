int mod = 1e9 + 7;
class Solution {
public:
    long long int func(string &s , int index ,vector<long long int> &dp  ){
        if(index >= s.length()){
            return 1 ; 
        }
        if(dp[index] != -1){
            return dp[index]; 
        }
        
        if(s[index] =='0'){
            return dp[index] =  0 ; 
        }
        long long int ans = func(s , index + 1 , dp) ; 
        if(s[index] == '*'){
            ans *= 9 ; 
            
            if(index + 1 < s.length() && s[index + 1] >= '0' && s[index+1] <= '9'){
                ans += func(s , index + 2 , dp ); 
            }
            
            if(index + 1 < s.length()  && s[index + 1] == '*'){
                ans += 9 *func(s, index + 2, dp ); 
            }
            if(index + 1 < s.length() && s[index + 1] >= '0' && s[index + 1] <= '6' )
            {
                ans += func(s, index + 2 ,dp ); 
            }
            if(index + 1 < s.length() && s[index + 1] =='*' ){
                ans = ans + (6*func(s, index + 2 ,dp)); 
            }
            
        }
        else if(s[index] =='1' && index+1 < s.length()){
            if(s[index + 1] >= '0' && s[index + 1] <= '9' ){
                ans += func(s, index + 2 ,dp ); 
            }
            else if(s[index + 1]  == '*'){
                ans += (9*func(s , index + 2 ,dp)); 
            }
        } 
        else if(s[index] == '2' && index + 1 < s.length()){
            if(s[index + 1] >= '0' && s[index + 1] <= '6'){
                ans += func(s , index + 2 ,dp); 
            }
            else if(s[index + 1] == '*'){
                ans += (6*func(s , index + 2 ,dp)); 
            }
        }
        return dp[index] = ans%mod ; 
    }
    int numDecodings(string s) {
          vector<long long int> dp (s.length() + 1 , -1); 
        return func(s , 0 ,dp  ); 
    }
};