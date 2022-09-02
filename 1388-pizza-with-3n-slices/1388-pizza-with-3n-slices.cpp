


class Solution {
public:
    int dp[501][170];
    int func(vector<int> &v , int i , int n    ){
        if(n ==  0 || i >= v.size() ) {
            return 0 ; 
        }
        if(dp[i][n] != -1){
            return dp[i][n]; 
        }
       
        return dp[i][n]= max(func(v , i+1,n),v[i]+func(v , i+2,n-1));
        
        
        
    }
    int maxSizeSlices(vector<int> &slices) {
        // vector<vector<int>> dp (slices.size() + 1 , vector<int>(slices.size() + 1 , -1)); 
          int n=slices.size();
        memset(dp,-1,sizeof(dp));
        
        //Case 1 ignore first element
        int p1=func(slices , 1,n/3); 
        memset(dp,-1,sizeof(dp));
        
        //Case 2 ignore last element
        slices[n-1]=0;
        int p2=func(slices, 0,n/3);
        return max(p1,p2);
    }
};