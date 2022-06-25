// { Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    vector<pair<int,int> >ans;
    int i=0;
    while(i<n){
        for(i;i<n-1 && price[i+1]<=price[i];i++);
        if(i==n-1)
            break;
        int buy = i;
        for(i;i<n-1 && price[i+1]>=price[i];i++);
        int sell = i;
        ans.push_back({buy,sell});
    }
    if(ans.empty()){
        printf("No Profit\n");
        return;
    }
    for(auto it: ans)
        printf("(%d %d) ",it.first,it.second);
    printf("\n");
}