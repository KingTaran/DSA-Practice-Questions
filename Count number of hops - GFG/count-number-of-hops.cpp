// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long  A[1000005]; 
    const long long  mod = 1000000007 ; 
    long long int countsteps(int n ){
        if(n<=0){
            return 0 ; 
        }
        if(n==1){
            return 1; 
        }
        if(n==2){
            return 2; 
        }
        if(n==3){
            return 4; 
        }
        if(A[n] != -1){
            return A[n]%mod ;  
        }
        A[n] =   countsteps(n-3)  + countsteps(n-1) + countsteps(n-2) ; 
        
        return A[n]%mod ; 
        
    }
    long long countWays(int n)
    {
        memset(A , -1 , sizeof(A)); 
        return countsteps(n); 
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends