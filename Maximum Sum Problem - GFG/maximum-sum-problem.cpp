// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution

//  Agar Intution Pata hai toh quesstion is very easy warna lage raho ghante bhar 


{
    public:
        int maxSum(int n)
        {
            int dp[n + 1]; 
            fill(dp , dp + n  +1 , INT_MIN );
            for(int i = 0 ; i <n+ 1 ; i ++){
                dp[i] = max(i , dp[i/ 3]+ dp[i/2]+ dp[i/4] ); 
            }  
            return dp[n]; 
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
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends