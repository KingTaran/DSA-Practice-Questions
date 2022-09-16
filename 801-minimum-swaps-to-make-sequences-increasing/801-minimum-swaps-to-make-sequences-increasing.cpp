class Solution {
public:
    int func(vector<int> &a ,vector<int> & b , int prev_a , int prev_b , int i , bool swap , vector<vector<int>> &dp){
        if(i == a.size()){
            return 0 ; 
        }
        if(dp[i][swap] != -1){
            return dp[i][swap] ; 
        }
        int no_swap = INT_MAX; 
        if(a[i] > prev_a && b[i] > prev_b){
            no_swap = func(a, b , a[i] , b[i] , i + 1 ,  0 , dp ); 
        }
        int swapp = INT_MAX ; 
        if(a[i] > prev_b && b[i] > prev_a){
            swapp = min(swapp , 1 + func(a,  b , b[i] , a[i] , i + 1 , 1 , dp )); 
        }
        return dp[i][swap]  = min(swapp , no_swap); 
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1 , vector<int> (2 , -1)); 
        return func(nums1 , nums2 , -1 , -1 , 0 , 0 , dp ); 
    }
};