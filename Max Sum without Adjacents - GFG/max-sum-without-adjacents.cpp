// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int A[100000]; 
	int helper(int *arr , int n   ){
	    if( n <= 0  ){
	        return 0 ; 
	    }
	    if(A[n] != -1){
	        return A[n]; 
	    }
	     int res  = arr[n-1] + helper(arr , n-2) ; 
	     int res2 = helper(arr , n-1); 
	    A[n] =  max(res , res2) ; 
	    return A[n]; 
	    
	}
	int findMaxSum(int *arr, int n) {
	    memset(A, -1,sizeof(A)); 
	    return helper(arr , n ) ;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends