// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template f

int maxProfit(vector<int>&price){
   //Write your code here..
   int fbuy=INT_MIN,fsell=0,sbuy=INT_MIN,ssell=0,i=0;
   
   while(i<price.size())
   {
       fbuy=max(fbuy,-price[i]);
       fsell=max(fsell,fbuy+price[i]);
       sbuy=max(sbuy,fsell-price[i]);
       ssell=max(ssell,sbuy+price[i]);
       i++;
   }
   return ssell;
}
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends