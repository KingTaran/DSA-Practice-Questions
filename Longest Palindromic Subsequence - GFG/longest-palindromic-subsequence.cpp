// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
   int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int t[x  + 1 ] [y + 1 ];
        memset(t , 0 , sizeof(t)) ; 
        for(int i = 0 ; i< x + 1 ; i++){
            for(int j = 0 ; j < y + 1 ; j++ ){
                if(i == 0 || j == 0){
                    t[i][j] = 0 ; 
                }
            }
        }
         for(int i = 1 ; i< x + 1 ; i++){
            for(int j = 1 ; j < y + 1 ; j++ ){
                if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1]; 
                }
                else{
                    t[i][j] =   max(t[i-1][j] , t[i][j-1]); 
                }
            }
        }
        
        
        
        
        
        
        return t[x][y] ; 
    }
    int longestPalinSubseq(string A) {
        int n = A.length() ; 
        string B  = A ; 
        reverse(B.begin() , B.end()); 
        int lcsres = lcs(n , n , A , B ); 
        return lcsres ;
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends