// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const long long int  mod = 1000000007; 
class Solution{
	public:
	long long int A[100005] ; 
	long long int fib(int n ){
	    if(n == 0 ){
	        return 1 ; 
	    }
	    if(n == 1){
	        return 1; 
	    }
	    if(A[n] != -1){
        return A[n] % mod   ; 
	    }
	     
	    A[n] = fib(n-1 ) + fib(n-2);
	    return A[n] % mod  ; 
 	    
	}
		int nthPoint(int n){
		 memset(A, -1 , sizeof(A)); 
		 return fib(n)   ; 
		 
		    
		    
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends