// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends

long long int A[100005]; 
const long long int mod = 1000000007;  
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    long long int helper(int arr[] , int n ){
        if(n<=0){
            return 0 ; 
        }
        if(A[n] != -1){
            return A[n] % mod ; 
        }
        long  long int res = arr[n-1]  + helper(arr , n-2); 
        long  long int res2 = helper(arr , n-1); 
        A[n] =  max(res , res2);
        return A[n] % mod ; 
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        memset(A , -1 , sizeof(A)); 
        return helper(arr , n ) % mod ; 
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends