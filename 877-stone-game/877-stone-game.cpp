class Solution {
public:
   
    bool stoneGame(vector<int>& piles) {
        int n = piles.size()-1; 
        vector<vector<int>> dp (n + 2 , vector<int > (n + 2 , -1)); 
        int alice_score = func(piles , 0 ,n ,dp); 
        int sum = 0 ; 
        sum = accumulate(piles.begin() , piles.end() , sum  ); 
        int bob_score = sum - alice_score ; 
        return alice_score > bob_score ? 1 : 0 ; 
    }
private:
     int func(vector<int> & v ,int i  , int j  ,vector<vector<int>>&dp){
        if(i == j ){
            return v[j]; 
        }
        if(i > j ){
            return 0 ; 
        }
         if(dp[i][j] != -1){
             return dp[i][j]; 
         }
        int choice1 = v[i]  + min(func(v, i + 2 , j  ,dp) , func(v , i + 1 , j - 1,dp));
       int choice2 = v[j]  + min(func(v, i + 1 , j - 1 ,dp) , func(v , i  , j - 2,dp));
       return dp[i][j] = max(choice1 , choice2);  
    }
};