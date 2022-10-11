class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        nums.push_back(1); 
        nums.insert(nums.begin() , 1); 
        dp.resize(nums.size() + 1 , vector<int> (nums.size() + 1 , -1)); 
        return func(1 , n , nums); 
    }
private : 
    vector<vector<int>>dp ; 
    int func(int i , int j , vector<int> &v ){
       if(i > j ){
           return 0; 
       } 
      if(dp[i][j] != -1){
          return dp[i][j]; 
      }
        int res = INT_MIN ; 
       for(int index = i ; index <=j ; index ++ ){
           int t = (v[i - 1 ] * v[index]* v[j + 1] ) + func(i , index-1 , v ) + func(index +1  , j , v ); 
           res = max(res , t); 
       } 
        return dp[i][j] = res ; 
        
        
    }
};