// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
         int n=arr.size();
        vector<vector<int>> ans;
        set<vector<int>> v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int start=j+1;
                int end=n-1;
                while(start<end){
                    long long int sum=(long long int)arr[i]+arr[j]+arr[start]+arr[end];
                    if(sum>k)
                    {
                        end--;
                    }
                    else if(sum<k)
                    {
                        start++;
                    }
                    else{
                        v.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }
                }              
                while(j+1<n and arr[j]==arr[j+1])
                    j++;
            }
            while(i+1<n and arr[i]==arr[i+1])
                i++;
        }
        for(auto i : v){
            ans.push_back(i);  // store the answers in an array(ans)
        }
        return ans;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends