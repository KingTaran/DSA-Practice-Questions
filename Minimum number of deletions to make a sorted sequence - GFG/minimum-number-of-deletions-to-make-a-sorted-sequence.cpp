// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
// This is a variation of Longest Increasing Subsequence
	public:
	int minDeletions(int a[], int n) 
	{ 
	    int dp[n+1] ; 
	    fill(dp , dp + n +1, 1) ; 
	    for(int  i =  1 ;i < n ; i++){
	        for(int j = 0 ; j < i ; j++){
	            if(a[j] < a[i]){
	                dp[i] = max(dp[i] , dp[j] + 1 ) ; 
	            }
	        }
	    }
	    int res  = INT_MIN ; 
	    for(int i = 0 ; i< n ; i++){
	        res = max(res , dp[i]); 
	    }
	    return  n-res  ; 
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends