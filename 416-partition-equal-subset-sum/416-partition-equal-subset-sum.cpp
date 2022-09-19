// One of the base question of many questions 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;  
        sum = accumulate(nums.begin() , nums.end() , sum ); 
        if(sum %2 != 0 ){
            return 0 ; 
        }
        else{
            dp.resize(sum + 1 , vector<int> (nums.size() + 1 , -1)); 
            return func(nums , nums.size() , sum /2); 
        }
        
        
        
    }
private:
    vector<vector<int>> dp ; 
    bool func(vector<int> &v , int n , int sum ){
        if(sum == 0 ){
            return  1;
        }
        if(sum < 0 ){
            return 0;  
        }
        if(n == 0 ){
            return 0 ; 
        }
        if(dp[sum][n] != -1){
            return dp[sum][n]; 
        }
        if(v[n-1] > sum ){
            func(v, n - 1 , sum ); 
        }
        return dp[sum][n] = func(v, n - 1 , sum ) || func(v, n - 1 , sum- v[n-1] ); 
        
    }
};
