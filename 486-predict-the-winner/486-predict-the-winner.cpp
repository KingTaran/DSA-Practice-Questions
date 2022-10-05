// Same approach as Optimal game Strategy 

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp (nums.size() + 1 , vector<int>(nums.size() + 1 , -1)); 
        if(nums.size() ==1 ){ 
            return 1;
        }
        int player1 = func(nums , 0 , nums.size()-1 ,dp);
        int player2 = min(func(nums , 1 , nums.size() -1,dp) ,func(nums , 0 , nums.size() -2,dp) );
        return player1 >= player2 ? 1 : 0 ; 
    }
    
private:
int func(vector<int> &v , int  i , int j  , vector<vector<int>>&dp) {
    if(i == j ){
        return v[i]; 
    }
    if(i > j ){
        return 0 ; 
    }
    if(dp[i][j] != -1){
        return dp[i][j]; 
    }
    int c1 = v[i] + min(func(v , i + 2 , j ,dp) , func(v, i + 1 , j -1,dp)); 
    int c2 = v[j] + min(func(v , i + 1 , j-1,dp) , func(v , i , j -2,dp)); 
    return dp[i][j] = max(c1, c2); 
}
};