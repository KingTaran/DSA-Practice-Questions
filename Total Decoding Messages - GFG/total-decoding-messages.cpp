// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

const long long int mod = 1000000007 ;
	long long  dp[100005]; 
class Solution {
	public:
	   long long  int Helper(string &str , int pos){
	        if(pos == str.length() )
	        {
	            return 1 ; 
	        }
	        
	        if(str[pos] == '0'){
	            return 0 ; 
	        }
	        if(dp[pos ]!= -1){
	            return dp[pos]%mod ; 
	        }
	        
	        
	        int res = Helper(str , pos + 1); 
	        if(pos + 1 < str.length() && (str[pos] == '1' or (str[pos] == '2'  && str[pos +1 ]<= '6')  ))    
             {
                 res += Helper(str, pos + 2); 
             }	      
             dp[pos ] = res%mod ;
	        return res%mod ;
	        
	        
	    }
		int CountWays(string str){
		    memset(dp , -1 , sizeof(dp)); 
		    long long int x = Helper(str , 0) ;
		    return x%mod ;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends