// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int A[100000] ; 

    long long int Helper(int n , int  k  ){
        if(n == 1){
            return k%1000000007 ; 
        }
        if( n == 2){
            long long int res = k%1000000007 +( k%1000000007 * (k-1)%1000000007); 
            return res%1000000007; 
        }
        if(A[n] != -1){
            return A[n] % 1000000007; 
        }
        long long int same = (k-1) * Helper(n-1 , k  ); 
        long long int diff = (k-1)*Helper(n-2 , k);
         A[n]  = same + diff ; 
         return A[n] % 1000000007; 
    }
    long long countWays(int n, int k){ 
        memset(A, -1 , sizeof(A)); 
        return Helper(n , k); 
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends