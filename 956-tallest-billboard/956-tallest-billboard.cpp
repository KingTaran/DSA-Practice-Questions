class Solution {
public:
    int dp[21][5005]; 
    int func(vector<int> &v , int left , int right , int i  ){
        if(i ==  v.size() ){
            if(left == right ){
                return 0 ; 
            }
            return -1000000; 
        }
    
    if(dp[i][abs(left - right)] != -1)
    {
        return dp[i][abs(left - right)]; 
    }
    return dp[i][abs(left - right)] = max(v[i] + func(v ,  left + v[i] ,  right ,  i+1  ) , max(v[i] +func(v , left ,  right+ v[i] ,  i+1  ), func(v ,  left ,  right , i+1  )));
    }
        
    int tallestBillboard(vector<int>& rods) {
        memset(dp , -1 , sizeof(dp)); 
     int sum =  0 ; 
        for(auto rod : rods ) { 
            sum += rod; 
    }
        return func(rods , 0 , 0 , 0)/2; }
};