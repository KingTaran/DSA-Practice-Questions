// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

bool vessel(int a[], int n, int k);



int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n+1];
        
        for(int i=0;i<n;i++)
            cin>> a[i];
        
        
        if(vessel(a, n, k)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
    return 0;
}
// } Driver Code Ends


bool isSubsetSum(int arr[], int sum , int n ){
        bool dp[n + 1 ][sum + 1]; 
        memset(dp , 0 , sizeof(dp)); 
        // int n = arr.size() ;  
        for(int i =  0 ; i  < n+ 1   ; i++){ 
            for(int j = 0 ; j < sum +   1; j ++){ 
                if ( i == 0 ){
                    dp[i][j] = 0 ; 
                }
                if(j == 0){
                    dp[i][j] = 1; 
                }
            }
        }
        for(int i = 1 ; i< n + 1  ; i ++) {
            for(int j = 1 ; j  < sum + 1 ; j++){
                if(arr[i-1] <= j ){
                    dp[i][j] = dp[i][j-arr[i-1]] || dp[i-1][j]; 
                }
                else{
                    dp[i][j] = dp[i-1][j]; 
                }
            } 
        }
        return dp[n][sum]; 
    }
bool vessel(int a[], int n, int k){

    return isSubsetSum(a , k , n); 
    
}