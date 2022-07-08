// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int helper(int n , int a[]){
        int dp[n+1]; 
        fill(dp , dp + n + 1 , INT_MAX); 
        dp[0] = INT_MIN ; 
        for( int i = 0 ; i < n ; i++){
            int idx = upper_bound(dp , dp+n + 1 , a[i]) -dp ; 
            if(a[i] >  dp[idx-1] && a[i] < dp[idx]){
                dp[idx] = a[i]; 
            }
        }
        int res  = 1 ; 
        for(int i = n ; i>=0 ; i--){
            if(dp[i] != INT_MAX){
                res = i ; 
                break ; 
            }
        }
        return  res;
        
    }
    
    
    
    
    
    int longestSubsequence(int n, int a[])
    {
       return helper(n , a); 
       
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends