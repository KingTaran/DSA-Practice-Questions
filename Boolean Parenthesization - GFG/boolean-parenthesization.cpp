// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int dp[201][201][2]; 
class Solution{
public:
    int Solve(string  S , int  n , int i , int j , bool isTrue  ){
        if(i >j  ){
            return 0 ; 
        }
        if(i == j ){
            if(isTrue == 1 ){
                return S[i] == 'T';
            }
            else{
                return S[i] == 'F'; 
            }
        }
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue] % 1003; 
        }
        int ans = 0 ; 
        for(int  k = i + 1 ; k < j ; k += 2){
            int lt = Solve(S , n , i , k-1 ,  1 ) ;
            int lf = Solve(S, n , i , k -1 ,  0 );
            int rt  = Solve(S, n ,  k + 1 , j  ,  1 );
            int rf = Solve(S, n , k +1, j  ,  0 );
            if(S[k]=='&'){
      if(isTrue)
       ans+=lt*rt;
      else
       ans+=lf*rf+lf*rt+lt*rf; 
     }
     else if(S[k]=='|'){
      if(isTrue)
       ans+=lt*rt+lf*rt+lt*rf;
      else
       ans+=lf*rf; 
     }
     else if(S[k]=='^'){
      if(isTrue)
       ans+=lt*rf+lf*rt;
      else
       ans+=lf*rf+lt*rt; 
     }
            
            
        }
        dp[i][j][isTrue] =  ans%1003  ; 
        return dp[i][j][isTrue] ; 
    }
    int countWays(int N, string S){
        // code here
        memset(dp  , -1 ,sizeof(dp)); 
        int res = Solve(S, N , 0 , N-1  , 1 );
        return res%1003 ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends