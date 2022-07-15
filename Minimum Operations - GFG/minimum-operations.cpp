// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:

  int func(int n ,vector<int> &dp ){
      if(n <= 3){
        return n ; 
    }
    if(dp[n] != -1){
        return dp[n] % 1000000007;   
    }
    int res1 =  func(n-1 ,dp ); 
    int res2 = func(n/2, dp ) + n % 2; 
    dp[n ]=  min(res1 , res2) + 1 ; 
    return dp[n] % 1000000007; 
      
  }
  
    int minOperation(int n)
    {
     vector<int> dp(n+1 , -1) ; 
     
    return func(n , dp ); 
  
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends