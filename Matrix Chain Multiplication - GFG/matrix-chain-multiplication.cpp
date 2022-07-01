// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int t[505][505]; 
class Solution{
public:
   int solve(int A[] , int i , int j , int n  ){
       if(i >= j ){
           return 0; 
        }
        if(t[i][j] != -1){
            int res  =  t[i][j];
            return res ;
        }
        int res = INT_MAX ; 
        for(int k = i ; k < j  ; k++){
            int tempans  = solve(A , i , k , n ) +  solve(A , k  +1 , j , n ) + A[i-1] * A[j ] * A[k]; 
            res = min(res , tempans);
        }
        t[i][j] = res;
        return res  ; 
   }
    int matrixMultiplication(int N, int arr[])
    {
        memset(t , -1 , sizeof(t)); 
        return 
        solve(arr , 1 , N -1 , N ); 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends