// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


/* This Question is  Based on Dynamic Programing Matrix Chain Multiplication  */

int t[1000][1000]; 

class Solution{
public:
bool isPalindrome(string &s , int i , int j ){
     while(i < j ){
         if(s[i] != s[j]){
             return 0 ; 
         }
         i++ ,j --; 
     }
     return 1 ; 
}
// This Solve Function is Similar to Matrix Chain Multiplicaton  
int Solve(string &s , int i , int j ){
    // Base Case
    if(i >= j ){
        return 0 ; 
    }
    // If the string is already a Palindome,  then we Will return 0;  
    if(isPalindrome(s , i , j ) == 1){
        return 0 ; 
    }
    
    // This is The Dp array
    if(t[i][j] != -1){
        // If  the element is Already Present in the Matrix, we return the  
        return t[i][j]; 
    }
    // The main solution Partitioning  Part
    int ans =INT_MAX; 
    for(int k = i ; k < j ; k++){
        int tempans = Solve(s , i , k ) + Solve(s , k + 1 , j ) + 1; 
        ans = min(ans , tempans); 
    }
    // Storing the Solution in DP matrix 
   t[i][j] = ans ;
   return ans ; 
    
    
}
    int palindromicPartition(string str)
    {
        // Initalizing  all the DP matrix element with -1
        memset(t , -1 , sizeof(t));
        return Solve(str, 0 , str.length()-1 ) ; 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
