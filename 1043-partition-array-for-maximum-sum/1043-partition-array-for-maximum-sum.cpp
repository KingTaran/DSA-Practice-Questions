class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size() + 1 , -1) ; 
        return func(arr , 0 , k  , arr.size()); 
    }
private : 
    vector<int> dp ; 
    int func(vector<int> & v ,int i , int k  , int n ){
        if(i == v.size()){
            return 0 ; 
            
        }
        if(dp[i] != -1){
            return dp[i]; 
        }
        int len = 0 ; 
        int max_element = INT_MIN  ; 
        int res = INT_MIN ; 
        for(int j = i ; j < min(i+ k , n) ; j ++ )
        {
            len ++; 
            max_element = max(max_element , v[j]) ; 
            int sum = len * max_element  + func(v , j + 1 , k , n  ) ; 
            res  = max(res  , sum );  
        }
        return dp[i] = res ; 
    }
};