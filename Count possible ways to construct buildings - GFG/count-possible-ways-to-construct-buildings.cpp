// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
	long long int A[100002] ; 
	/* DP by Aditya verma Made DP So Freaking Easy 
	I can't imagine dp without Aditya verma */ 
class Solution{
	public:
	
	long long int ways(int n ){
	    if(n == 0 ){
	        return 0 ; 
	    }
	    if(n == 1){
	        return 1; 
	    }
	    if(A[n] != -1){
	        return A[n]%1000000007; 
	    }
	    
	    A[n] = ways(n-1)%1000000007 + ways(n-2)%1000000007; 
	    return A[n]%1000000007; 
	    
	    
	    
	}
	int TotalWays(int N)
	{
	    if(N == 0 ){
	        return 1156; 
	    }
	    memset(A, -1 ,  sizeof(A)); 
      long long  int res = ways(N +  2 ) ;
       res = res %1000000007 * res%1000000007; 
       return res % 1000000007; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends