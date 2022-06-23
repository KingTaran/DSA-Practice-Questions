// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>  minmum(int n, vector<int>currency){
        vector<int> v ;
        if(n==0){
            return{};
        }
        for(int i = 9;i>=0;i--){
            if(n>=currency[i]){
                v.push_back(currency[i]);
               n =  n-currency[i];
                i ++ ; 
            }
        }
        return v; 
    }
    vector<int> minPartition(int N)
    {
        // code here
        vector<int>currency = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int > v ;
        v = minmum(N, currency);
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends