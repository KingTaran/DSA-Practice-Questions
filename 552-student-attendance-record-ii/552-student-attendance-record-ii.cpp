class Solution {
public:
    int mod = 1e9+7; 
    int dp[100005][2][3]; 
    long long  int func(int n , int a , int l ){
    if(a== 2 || l == 3){
        return 0 ; 
    }
    if(n== 0 ){
        return 1; 
    }
        if(dp[n][a][l] != -1){
            return dp[n][a][l] ; 
        }
    long long int ans  = 0;
    ans = func(n-1 , a , 0  )%mod; 
    ans = (ans + func(n-1 , a+1 , 0 )%mod)%mod;
    ans = (ans + func(n-1 , a  , l+1)%mod)%mod; 
     return dp[n][a][l] =  ans; 
    
}
    int checkRecord(int n) {
        memset(dp , -1 , sizeof(dp)); 
        return func(n , 0  , 0 ); 
    }
};