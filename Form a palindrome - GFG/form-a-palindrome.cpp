// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

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
    int countMin(string str){
    string x = str; 
    reverse(x.begin() , x.end()); 
    int lpsres = lcs(str.length() ,  x.length() , str , x ); 
    return str.length() - lpsres ;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends