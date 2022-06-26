// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long int A[100005]; 
    long long int CountWays(int n ){
        if(n == 0 ){
             return 1 ; 
         }
         if(n ==1){
             return 1; 
         }
         if(A[n] != -1){
             return A[n]%1000000007;  
         } 
         A[n]  = CountWays(n-1) + CountWays(n-2);
         return A[n]  %1000000007; 
    }
    int countWays(int n)
    {
        if(n == 0 || n ==1 ){
            return 1 ; 
        }
          memset(A , -1 , sizeof(A)); 
         return  CountWays(n ); 
         
         
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends