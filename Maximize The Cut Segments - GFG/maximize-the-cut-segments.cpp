// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

int t[100005] ; 
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximumcuts(int n , int x ,int y , int z){
        if(n == 0 ){
          return 0; 
       }
       if(n < 0 ){
           return -1; 
       }
       if(t[n] ){
           return t[n]; 
       }
        int res1 =   maximumcuts(n - x , x , y , z );
        int res2 = maximumcuts(n - y , x , y , z );
        int res3 =   maximumcuts(n - z , x , y , z );
      t[n] =   1 + max(res1 , max(res2  , res3)); 
      return t[n] = t[n] == 0?-1 : t[n]; 
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
    memset(t , 0 , sizeof(t));
    return maximumcuts(n , x , y , z) == -1 ? 0 : maximumcuts(n  , x , y ,z ) ; 
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends