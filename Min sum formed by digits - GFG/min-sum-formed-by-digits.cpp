// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        if(n == 1){
            return arr[0]; 
        }
        sort(arr, arr+ n); 
     string s1 = " "; 
     string s2 = " " ; 
     bool f =  1; 
     for(int i =  0 ; i <  n ; i++){
         if(f ){
             s1 += '0' + arr[i]; 
             f = 0 ; 
             
         }
         else{
             s2+= '0' + arr[i ]; 
             f = 1; 
         }
         
     }
    //  reverse(s1.begin() , s1.end());
    //  reverse(s2.begin() , s2.end());
     long long int num1 = stoll(s1); 
     long long int num2 = stoll(s2);
     return num1 + num2; 
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
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends