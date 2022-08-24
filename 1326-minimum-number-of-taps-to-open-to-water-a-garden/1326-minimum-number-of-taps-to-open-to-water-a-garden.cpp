class Solution {
    // This Question is difficult to understand 
    // This Question is important 
public:
    int minTaps(int n, vector<int>& A) {
        vector<int>  dp (n + 1 , n +2); 
        dp[0] = 0 ; 
        for(int i = 0 ; i<= n ; i++){
            int left = i - A[i]; 
            int right = i + A[i] ; 
            for(int j = max(0 , left ) ; j  <= min(i + A[i ] , n ) ; j++){
                dp[j] = min(dp[j] , dp[max(0 , left )] + 1  ); 
            }
        }
        // for(auto x  : dp){
        //     cout<< x <<" "; 
        // }
        return dp[n] < n +2 ?  dp[n] : -1 ; 
    }
};



         /*** 0      1      2      3      4      5
          3      4      1      1      0      0    
          ..........i1..........
                  ....................i2......
                 .........i3....
                         ..........i4...
           ....................i5..............***/    