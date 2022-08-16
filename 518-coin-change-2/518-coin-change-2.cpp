class Solution {
public:
     long long int perfectSum( vector<int>  arr, long long int n, long long int sum)
	{
        long long int  t[n+1][sum + 1] ; 
        memset(t , 0 , sizeof(t)); 
        for(int i = 0 ; i<= n  ; i++){
            for(int j = 0 ; j <= sum  ; j++){
                if(i == 0 ){
                    t[i][j] = 0 ; 
                }
                
                if(j==0){
                    t[i][j] = 1; 
                }
            }
        }
        for(int i = 1 ; i< n + 1 ; i++){
            for(int j = 0 ; j < sum + 1 ; j++){
                if(arr[i-1] <= j ){
                    t[i][j] = t[i][j-arr[i-1]]  + t[i-1][j]  ; 
                }
                else{
                    t[i][j] = t[i-1][j] ; 
                }
            }
        }
        return t[n][sum] ; 
        
        
        
        
        
        
	}
    int change(int amount, vector<int>& coins) {
        return perfectSum(coins , coins.size() , amount);  
    }
};