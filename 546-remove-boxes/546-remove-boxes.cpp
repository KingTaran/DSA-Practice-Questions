class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        if(boxes.size() == 0){
            return 0 ; 
        }
        memset(dp , -1, sizeof(dp)); 
        return func(boxes , 0 , boxes.size() -1 , 0 ); 
    }
private: 
    int dp[101][101][101]; 
    int func(vector<int> & v, int left  , int right , int streak  ){
        if(left > right){
            return 0 ; 
        }
        if(left == right){
            return (streak+1)*(streak + 1); 
        }
        if(dp[left][right][streak] != -1){
            return dp[left][right][streak]; 
        }
        int maxi = func(v , left + 1 , right , 0 ) +((streak+ 1 ) * (streak+ 1)); 
        for(int i = left+1 ; i<= right ; i++){
            if(v[left ] == v[i]){
                maxi = max(maxi , func(v,  left + 1  , i -1 , 0 )  + func(v, i , right  , streak + 1) ); 
            }
            
        }
        return dp[left][right][streak] =maxi ;
    }
};