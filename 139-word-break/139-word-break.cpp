class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
     unordered_map<string , bool > m ;
        for(auto x : wordDict){
            m[x] = 1; 
        }
        return  func(s , m ) ; 
        
    }
    
    
private:
    unordered_map<string , bool > dp ; 
    
int func(string s , unordered_map<string , bool > &m ){
    if(m.find(s) != m.end() ) {
        return 1; 
    }
    if(dp.find(s) != dp.end()){
        return dp[s]; 
    }
    for(int i = 0 ; i< s.size() ; i++){
        string left = s.substr(0 , i +1); 
        string right = s.substr(i + 1); 
        if(m.find(left ) != m.end()){
            bool res  = func(right , m ) ; 
            if(res ){
                return dp[s] = 1; 
            }
        }
    }
    return dp[s] = 0 ; 
    
}
};