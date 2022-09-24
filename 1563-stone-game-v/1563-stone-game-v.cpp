// class Solution {
// public:
//     int stoneGameV(vector<int>& v) {
//        return func(v , 0 , v.size() -1);   
//     }
// private : 
//     int func(vector<int> &v , int i , int j ){
//         if(i > j ){
//             return 0 ; 
            
//         }
        
//         int right =  0 ; 
//         for(int k = i ; k <= j ; k++){
//             right += v[i] ; 
//         }
//         int left  =0 , res = 0 ; 
//         for(int k = i ; k < j ; k++){
//             left += v[k] ; 
//             right -= v[k] ; 
//             if(left < right ){
//                 res = max(res , left + func(v, i , k )); 
//             }
//             if(right < left){
//                 res = max(res , right + func(v , k + 1 , j )); 
//             }
//             if(left == right ){
//                 res = max(res , left + max(func(v , k + 1 , j ) , func(v, i , k ) ));
//             }
            
//         }
//     return res ;
        
//     }
// };
class Solution {
public:
    vector<int> prefixSum;			//Stores prefixSums
    vector<vector<int>> memo;
    int dp(vector<int>& stoneValue,int i,int j)
    {
        if(i==j)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j]=0;
        for(int p=i+1;p<=j;p++)		//Try each partition.
        {
			int l=prefixSum[p]-prefixSum[i],r=prefixSum[j+1]-prefixSum[p];
			if(l<r)		//Left part is smaller
                memo[i][j]=max(memo[i][j],l+dp(stoneValue,i,p-1));
            else if(l>r)	//Right part is smaller
                memo[i][j]=max(memo[i][j],r+dp(stoneValue,p,j));
            else	//Both parts are equal
                memo[i][j]=max(memo[i][j],l+max(dp(stoneValue,p,j),dp(stoneValue,i,p-1)));
        }
        return memo[i][j];
    }
    int stoneGameV(vector<int>& stoneValue)
    {
        memo.resize(stoneValue.size(),vector<int>(stoneValue.size(),-1));
        prefixSum.resize(stoneValue.size()+1,0);
        for(int i=0;i<stoneValue.size();i++)		//Create prefix Sums
            prefixSum[i+1]=prefixSum[i]+stoneValue[i];
        return dp(stoneValue,0,stoneValue.size()-1);
    }
};