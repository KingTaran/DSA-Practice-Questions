class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        dp.resize(v.size() + 1  , -1)  ;
        int x = func(v , 0  ); 
        if(x > 0 ){
            return "Alice"; 
        }
        if(x == 0 ){
            return "Tie"; 
        }
        return "Bob"; 
    }
    private: 
    vector<int>dp ; 
    int func(vector<int> & v ,int i  ){
        if(i >= v.size() ){
            return 0 ; 
        }
        int res =INT_MIN; 
        if(dp[i] != -1){
            return dp[i] ; 
        }
        res  = max(res , v[i]  - func(v , i + 1  )); 
        if(i +1< v.size()){
        res = max((v[i] + v[i + 1 ]) - func(v , i + 2) , res ) ;}
        if(i + 2 < v.size()){
         res = max(res ,   (v[i] + v[i + 1 ] + v[i + 2] ) - func(v , i + 3)) ;}
        return dp[i] = res ; 
    }
    
};