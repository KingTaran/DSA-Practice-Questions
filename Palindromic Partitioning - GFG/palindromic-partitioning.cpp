// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
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
int Solve(string &s , int i , int j ){
    if(i >= j ){
        return 0 ; 
    }
    if(isPalindrome(s , i , j ) == 1){
        return 0 ; 
    }
    if(t[i][j] != -1){
        return t[i][j]; 
    }
    int ans =INT_MAX; 
    for(int k = i ; k < j ; k++){
        int tempans = Solve(s , i , k ) + Solve(s , k + 1 , j ) + 1; 
        ans = min(ans , tempans); 
    }
   t[i][j] = ans ;
   return ans ; 
    
    
}
    int palindromicPartition(string str)
    {
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