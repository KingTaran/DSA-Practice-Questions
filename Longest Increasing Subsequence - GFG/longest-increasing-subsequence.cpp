// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// This is One of the base concepts of Dynamic Programming 
/* -------------------------------------------------------------------------- */
/*                              Question Details                              */
/* -------------------------------------------------------------------------- */
/**
 * *This is one of the important  question in Dynamic Programming 
 * * So , therefore understanding the  Concept behind this Question 
 * *is Really important 
 */
// Difficulty : Medium 

//  Implementation 
// example : 
//  n = 6 , a[] = 5 8 3 7 9 1  
// Initally : dp[] = INT_MIN INT_MAX INT_MAX INT_MAX INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 

// for: 
// after i = 0 
// Initally : dp[] = INT_MIN     5   INT_MAX INT_MAX INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 



// after i = 1
// Initally : dp[] = INT_MIN     5   8     INT_MAX INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 
// after i = 2
//  Initally : dp[] = INT_MIN    3    8     INT_MAX INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 
 
 
// after i = 3 
// Initally : dp[] = INT_MIN     5     7     INT_MAX INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 
// after i = 4 
// Initally : dp[] = INT_MIN     5     7     9  INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 
// after i = 5 
 
// Initally : dp[] = INT_MIN     1     7     9  INT_MAX INT_MAX INT_MAX
//                       0       1     2      3       4       5        6 
// so we return the last index whose value is not Equal to INT_MAX
/* -------------------------------------------------------------------------- */
/*                                Code Section                                */
/* -------------------------------------------------------------------------- */


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int helper(int n  , int a[] ){
        int dp[n+ 1 ]; 
        fill(dp , dp + n + 1 , INT_MAX); 
        dp[0] = INT_MIN ; 
    for(int i = 0  ; i < n ; i++){
        int idx = upper_bound(dp ,dp + n + 1 , a[i] ) -dp; 
        if(a[i] > dp[idx -1] && a[i] < dp[idx] ){
            dp[idx] = a[i] ; 
        }
    }
    
    for(int i = n ; i>=0  ; i --){
        if(dp[i]!= INT_MAX ){
            return i ; 
        }
    }
    
    
    
    
    }
    int longestSubsequence(int n, int a[])
    {
       return helper(n , a) ; 
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