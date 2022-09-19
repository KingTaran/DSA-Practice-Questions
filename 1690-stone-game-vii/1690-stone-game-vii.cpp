class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        dp.resize(stones.size() + 1 , vector<int>(stones.size() + 1 , -1));  
        int sum = 0 ; 
        sum  = accumulate(stones.begin() , stones.end() , sum ); 
        return func(stones , 0 , stones.size() -1 , sum); 
    }
private: 
    vector<vector<int>> dp ; 
    int func(vector<int> &v  , int i , int j , int sum  ){
        if( i== j ){
            return 0   ; 
        }
        if(i > j ) {
            return 0 ; 
        }
        if(dp[i][j] != -1){
            return dp[i][j]; 
        }
        int choice1 = sum - v[i] - func(v , i + 1 , j , sum - v[i] ); 
        int choice2= sum -v[j] - func(v, i , j -1 , sum-v[j]); 
        return dp[i][j] = max(choice1 , choice2); 
        
        
        
    }
};