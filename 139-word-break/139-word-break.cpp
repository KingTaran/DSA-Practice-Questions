class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string , bool > m ; 
        for(auto x : wordDict){
            m[x] = 1; 
        }
        return func(s , m ); 
    }
    
private :
    unordered_map<string , bool > dp ; 
    bool  func(string s  , map<string , bool>  &dict ){
        if(dict.find(s) != dict.end()){
            return 1; 
        }
        if(dp.find(s)!= dp.end()){
            return dp[s]; 
        }
        
        for(int i = 0 ; i< s.size() ; i++){
            string left = s.substr( 0 ,i+1 ); 
            string right = s.substr(i + 1); 
            if(dict.find(left) != dict.end()){
                bool ros = func(right,  dict);
                if(ros==1 ){
                    dp[s] = 1; 
                    return 1; 
                }
            }
        }
        dp[s] = 0 ; 
         return 0 ; 
    }
};