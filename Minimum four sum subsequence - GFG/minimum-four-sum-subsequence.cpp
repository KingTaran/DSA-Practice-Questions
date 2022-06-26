// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*You are required to complete below method */

class Solution{
    public:
    int minSum(int arr[], int n){
        if(n == 0){
            return 0 ; 
            
        }
        if (n == 1){
            return arr[0]; 
        }
        if(n==2){
            return min(arr[0] , arr[1]); 
        }
        if(n==3){
            return min(arr[0] , min(arr[1] , arr[2] )); 
        
        
        
        if(n == 4){
            return min(arr[0 ] , min(arr[1] , min(arr[2] , arr[3])));
        }
        int e , ans ;
        int a = arr[0] ; 
        int b =arr[1]; 
        int c = arr[2 ]; 
        int d = arr[3]  ; 
        for(int i = 4 ; i < n ; i++){
            e = arr[i] + min(a ,min( b ,min( c , d))); 
            a  = b; 
            b = c  ; 
            c = d ; 
            d = e; 
        }
        return min(a ,min( b ,min( c ,min(d , e )))); 
        
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends