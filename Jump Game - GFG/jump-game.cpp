// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
// Easy Peasy Lemon Squeezee 
// This is Not a Dynamic Programming Question 
// I have done the same question before Link to exact Same Question : https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1/ 

class Solution {
  public:
    int canReach(int A[], int N) {
        int max_range = A[0] ;
        int jump = 1; 
        int steps = A[0]; 
        if(N == 1 ){
            return 1 ;
        }
        for(int i = 1 ; i <  N ; i++){
            if(i == N-1){
                return 1 ;
            }
            max_range = max(max_range , A[i]  + i ); 
            steps--; 
            if(steps == 0 ){
                jump++; 
            }
            if(max_range <= i ){
                return 0; 
            }
            steps = max_range - i ; 
        }
        
        return 0; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends