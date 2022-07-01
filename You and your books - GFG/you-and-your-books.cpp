// { Driver Code Starts
#include <iostream>
#include<algorithm>
#include<cstdio>
//#include<Windows.h> 
using namespace std;  

 // } Driver Code Ends

class Solution{
    public:
    /*You are requried to complete this method */
    int max_Books(int a[], int n, int k)
    {
       long long  int sum = 0 ; 
       long long int books = 0 ; 
       for(int i = 0 ; i <n ; i++){
           if(a[i] <= k ){
               sum += a[i]%1000000007;
               if(a[i+1] <= k && i+1 < n){
                   continue; 
               }
               else{
                   books = max(sum%1000000007 , books%1000000007 ); 
                   sum = 0 ; 
               }
           }
       }
       return books%1000000007 ;
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
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>ar[i];
  	}
  	Solution ob;
  	cout<<ob.max_Books(ar,n,k)<<endl;
        
  }    
  return 0;
}

  // } Driver Code Ends