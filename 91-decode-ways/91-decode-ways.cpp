class Solution {
public:
    int numDecodings(string s) {
        dp.resize(s.size() + 1 , -1  ) ; 
        return func(s , 0 ) ; 
    }
private: 
    vector<int>dp ; 
    int func(string & s, int i )
    {
        if(s[i] == '0'){
            return 0  ;
        }
        if(i >= s.size()){
            return 1; 
        }
        if(dp[i] != -1){
            return dp[i]; 
        }
        if(i + 1 < s.size() && (s[i] =='1' || (s[i] == '2' &&(  s[i + 1 ]<= '6' && s[i+1] >= '0' ) )) ){
       return dp[i] = func(s , i +1  ) + func(s , i + 2); 
        }
        else{
           return   dp[i] = func(s , i +1); 
        }
        
        
    }
};