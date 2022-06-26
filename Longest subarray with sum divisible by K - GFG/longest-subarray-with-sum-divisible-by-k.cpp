// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
     // this question is solved in series of Microsoft in 29 days GFG series. 
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int res = INT_MIN  ; 
	    int sum = 0 ; 
	    map<int ,int > m ; 
	    for(int i = 0 ; i< n ; i++){
	        sum += arr[i];
	        int rem = sum % k ; 
	        if(sum % k == 0){
	            res = max(res , i + 1); 
	        }
	       // This Condition is Really very Important
	        if(rem < 0 ){
	            rem += k ; 
	        }
	        
	       //All the other things in the code is same as Longest subarr with sum = 0 
	     if(m.find(rem) == m.end() ){
	            m[rem] = i ; 
	        }
	        else{
	           res = max(res ,abs( m[rem] - i)  ); 
	        }
	    }
	    return res == INT_MIN ?  0  : res  ;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends