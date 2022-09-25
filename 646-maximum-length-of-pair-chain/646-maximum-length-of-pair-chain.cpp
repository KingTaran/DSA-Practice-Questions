class Solution {
public:
    int dp[1005][2005];
    
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    
    int func(vector<vector<int>> &v, int i,int start,int end){
        if (i==v.size()){
            return 0;
        }
        
        if (dp[i][abs(start)+abs(end)]!=-1){
            return dp[i][abs(start)+abs(end)];
        }
        
        int val=0;
        if (v[i][0]>end){
            val=1+func(v,i+1,v[i][0],v[i][1]);
        }
        
        val=max(val,func(v,i+1,start,end));
        
     return dp[i][abs(start)+abs(end)]=val;
    }
    
    int findLongestChain(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        
        int start=-1001,end=-1001;
        sort(v.begin(),v.end(),cmp);
      return  func(v,0,start,end);
    }
};