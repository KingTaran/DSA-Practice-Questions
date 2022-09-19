class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        return minimumDifference(stones ); 
    }
private :
     int minimumDifference(vector<int>& arr) {
        // return -1; 
        int sum = 0 ; 
        int n = arr.size(); 
	    for(int i = 0 ; i < n ; i++)
	    {
	        sum += arr[i] ; 
	    }
        // if(sum < 0 ){
        //     return 0 ; 
        // }
        if(sum == 0 ){
            return abs (arr[0]-arr[1]);
        }
        // if( n==2){
        //     return sum ; 
        // }
	    dp.resize(sum + 1 , vector<int> (n + 1 , -1)); 
	    bool range[sum + 1]; 
	    fill(range , range + sum + 1 , 0 ) ;
         range[0] = range[sum] = 1 ; 
	    for(int i = 1 ; i<sum ; i++){
	        range[i] = func(arr , n , i ); 
	    }
        int res = sum; 
        for(int i = 1 ; i <=sum ; i++){
            if(range[i] == 1 && range[sum - i ] == 1){
                 
                res = min(res , abs (sum - 2*i) ); 
            }
        }
        return res ;
    }
    vector<vector<int >> dp ; 
    bool func(vector<int> & v, int n  ,int sum ){
        if(sum == 0 ){
            return 1; 
        }
        if(n == 0 ){
           return 0 ; 
        }
        if(dp[sum][n] != -1){
            return dp[sum][n]; 
        }
        if(sum < v[n-1] ){
            return func(v , n -1 , sum); 
        }
        return dp[sum][n] = func(v, n -1 , sum - v[n-1]) || func(v, n -1 , sum);  
        
    }
};