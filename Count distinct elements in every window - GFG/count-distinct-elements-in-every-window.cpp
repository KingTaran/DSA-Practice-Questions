// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        map<int , int> m ; 
        
        vector<int > res; 
        
        int i = 0 ; 
         
        for( int j = 0 ; j < k ; j++){
                m[A[j]]++; 
        }
        // cout<<m.size() <<" #";
        res.push_back(m.size()); 
        int j = k ; 
        while(j < n ){
            m[A[j]]++; 
            m[A[i]] -- ;
            if(m[A[i]] == 0){
                m.erase(A[i]); 
            }
            res.push_back(m.size()); 
            i++;
            j++; 
            
        }
        return res ; 
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends