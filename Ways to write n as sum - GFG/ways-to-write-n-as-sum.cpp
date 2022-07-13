// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
     long long int perfectSum( int arr[], long long int n, long long int sum)
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
    int countWays(int n)
    {
        int arr[n]; 
        for(int i = 0 ; i< n ; i++){
            arr[i] = i+1 ; 
        }
        return perfectSum(arr, n , n )-1; 
        
        
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends