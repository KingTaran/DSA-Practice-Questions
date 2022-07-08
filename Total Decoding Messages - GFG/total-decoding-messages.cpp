// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	long long int t[100005] ;  
	int helper(int i , string s ){
	    if(s[i] == '0' ){
	        return 0 ; 
	    }
	    if(t[i] != -1){
	        return t[i]%1000000007; 
	    }
	    
	    if(i >= s.size()){
	        return 1;
	    }
	    if(i == s.size() -1){
	        return 1;
	    }
	    if(i + 1 < s.size() && (s[i] == '1' ||(s[i]  == '2' && (s[i + 1] >= 48 && s[i+1] <=54 )))){
	        t[i] =  helper(i + 1  ,  s) + helper(i + 2 , s); 
	        return t[i] % 1000000007;
	    }
	    else{
	        t[i] =  helper(i + 1 , s);
	        return t[i]%1000000007;
	    }
	    
	    
	}
		int CountWays(string str){
		    memset(t , -1 , sizeof(t)); 
		    return helper(0 , str ) ; 
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