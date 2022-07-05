// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[202][202]; 
    int func(int n , int f ){
        if(f == 0 || f == 1 ){
            return f ;
        }
        if(n == 0 ){
            return 0 ; 
        }
        if(n ==1 ){
            return f ; 
        }
        if(t[n][f] != -1){
            return t[n][f]%1000000007; 
        }
        int res = INT_MAX ; 
        for(int k = 1 ; k<= f ; k++ ){
            int tempans = 1 + max(func(n-1 ,k- 1  ) , func(n , f - k )); 
            res = min(res , tempans );  
        }
        t[n][f]  =res%1000000007; 
        return res%1000000007 ;
        
        
        
        
    }
    
    
    int eggDrop(int n, int k) 
    {
        memset(t, -1 , sizeof(t)); 
        return func(n , k); 
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends