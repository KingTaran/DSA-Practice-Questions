// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        sort(arr , arr + n  , greater<int > ()); 
        int i = 0 , j  =1 ;
        int res =  0 ; 
        while(i < n-1 && j < n){
            if(arr[i] - arr[j] < k ){
                res += arr[i] + arr[j] ;
             i = i + 2; 
             j = j + 2 ; 
                 
            }
            else{
            i ++ , j++; }
        }
        return res ; 
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends